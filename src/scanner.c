#include <tree_sitter/parser.h>
#include <wctype.h>

#pragma GCC diagnostic ignored "-Wunused-parameter"

enum TokenType {
  LINE_BREAK,
  L_BRACKET,
  INT,
  FLOAT,
  QUOTED_STRING,
  UNQUOTED_STRING,
  WHITESPACE,
  COMMA,
  LINE_COMMENT,
  SECTION_NAME,
  KEY,
};

void *tree_sitter_bni_external_scanner_create() { return NULL; }
void tree_sitter_bni_external_scanner_destroy(void *payload) {}
void tree_sitter_bni_external_scanner_reset(void *payload) {}
unsigned tree_sitter_bni_external_scanner_serialize(void *payload, char *buffer) { return 0; }
void tree_sitter_bni_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {}

static inline bool is_newline(int32_t c) {
  return c == '\n' || c == '\r';
}

bool tree_sitter_bni_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
  // LINE_BREAK
  if (valid_symbols[LINE_BREAK]) {
    if (lexer->lookahead == '\n') {
      lexer->advance(lexer, true);
      lexer->result_symbol = LINE_BREAK;
      return true;
    }
    if (lexer->lookahead == '\r') {
      lexer->advance(lexer, true);
      if (lexer->lookahead == '\n') lexer->advance(lexer, true);
      lexer->result_symbol = LINE_BREAK;
      return true;
    }
  }

    // COMMA
    if (valid_symbols[COMMA] && lexer->lookahead == ',') {
      lexer->advance(lexer, false);
      lexer->result_symbol = COMMA;
      return true;
    }

  // START OF LINE: SECTION vs ITEM
  if (valid_symbols[WHITESPACE] && valid_symbols[L_BRACKET] && valid_symbols[KEY]) {
      bool eat_ws = false;

      // 1. Жрём пробелы
      while (lexer->lookahead == ' ' || lexer->lookahead == '\t') {
          lexer->advance(lexer, false);
          eat_ws = true;
      }

     // 2. После пробелов:
         if (eat_ws) {
             // 2.1. [ или // → WHITESPACE
             if (lexer->lookahead == '[' ||
                 (lexer->lookahead == '/' && lexer->lookahead != 0 && lexer->lookahead == '/')) {
                 lexer->result_symbol = WHITESPACE;
                 lexer->mark_end(lexer);
                 return true;
             }

             // 2.2. \n → пробелы съели, но ничего полезного — значит KEY
             if (is_newline(lexer->lookahead) || lexer->eof(lexer)) {
                 lexer->result_symbol = KEY;
                 lexer->mark_end(lexer);
                 return true;
             }
         }

      // 3. Без пробелов: [ → L_BRACKET
      if (lexer->lookahead == '[') {
          lexer->advance(lexer, false);
          lexer->result_symbol = L_BRACKET;
          lexer->mark_end(lexer);
          return true;
      }

      // 4. Без пробелов: // → LINE_COMMENT
      if (lexer->lookahead == '/') {
          lexer->advance(lexer, false);
          if (lexer->lookahead == '/') {
              lexer->advance(lexer, false);
              while (!lexer->eof(lexer) && !is_newline(lexer->lookahead)) {
                  lexer->advance(lexer, false);
              }
              lexer->result_symbol = LINE_COMMENT;
              lexer->mark_end(lexer);
              return true;
          } else {
              return false;
          }
      }

      // 5. Если = сразу, или \n, или eof — не ключ
      if (lexer->lookahead == '=' || is_newline(lexer->lookahead) || lexer->eof(lexer)) {
          return false;
      }

      // 6. Жрём до = или конца строки
      bool eat_key = false;
      while (!lexer->eof(lexer) &&
             lexer->lookahead != '=' &&
             !is_newline(lexer->lookahead)) {
          lexer->advance(lexer, false);
          eat_key = true;
      }

      // 7. Если хоть что-то съели — это KEY
      if (eat_key) {
          lexer->result_symbol = KEY;
          lexer->mark_end(lexer);
          return true;
      }

      return false;
  }

    // SECTION_NAME
    if (valid_symbols[SECTION_NAME]) {
      if (lexer->lookahead != 0 && lexer->lookahead != ']' && !is_newline(lexer->lookahead)) {
        while (lexer->lookahead != 0 && lexer->lookahead != ']' && !is_newline(lexer->lookahead)) {
          lexer->advance(lexer, false);
        }
        lexer->result_symbol = SECTION_NAME;
        return true;
      }
    }

    // INT / FLOAT
    if ((valid_symbols[INT] || valid_symbols[FLOAT]) &&
        (lexer->lookahead == '-' || lexer->lookahead == '.' ||
         (lexer->lookahead >= '0' && lexer->lookahead <= '9'))) {

      bool is_float = false;

      if (lexer->lookahead == '-') {
        lexer->advance(lexer, false);
      }

      while (lexer->lookahead >= '0' && lexer->lookahead <= '9') {
        lexer->advance(lexer, false);
        lexer->mark_end(lexer);
      }

      if (lexer->lookahead == '.') {
        is_float = true;
        lexer->advance(lexer, false);

        while (lexer->lookahead >= '0' && lexer->lookahead <= '9') {
          lexer->advance(lexer, false);
          lexer->mark_end(lexer);
        }
      }

      // 1. Прямое завершение
      if (lexer->lookahead == ',' || is_newline(lexer->lookahead) || lexer->eof(lexer)) {
        lexer->result_symbol = is_float ? FLOAT : INT;
        return true;
      }

      // 2. Пробелы — допустимы (но не расширяют токен)
      if (lexer->lookahead == ' ' || lexer->lookahead == '\t') {
        do {
          lexer->advance(lexer, false);
        } while (lexer->lookahead == ' ' || lexer->lookahead == '\t');

        if (lexer->lookahead == ',' ||
            is_newline(lexer->lookahead) ||
            lexer->eof(lexer)) {
          lexer->result_symbol = is_float ? FLOAT : INT;
          return true;
        }

        if (lexer->lookahead == '/') {
          lexer->advance(lexer, false);
          if (lexer->lookahead == '/') {
            lexer->result_symbol = is_float ? FLOAT : INT;
            return true;
          }
        }
      }
    }

 // WHITESPACE (in value_list)
 if (valid_symbols[WHITESPACE]) {
   if (lexer->lookahead == ' ' || lexer->lookahead == '\t') {
     do {
       lexer->advance(lexer, false);
       lexer->mark_end(lexer);
     } while (lexer->lookahead == ' ' || lexer->lookahead == '\t');

     if (is_newline(lexer->lookahead) || lexer->eof(lexer)) {
       lexer->result_symbol = WHITESPACE;
       return true;
     }

     if (lexer->lookahead == '/') {
       lexer->advance(lexer, false);
       if (lexer->lookahead == '/') {
         lexer->result_symbol = WHITESPACE;
         return true;
       }
     }
   }
 }

  // QUOTED_STRING
  if (valid_symbols[QUOTED_STRING] &&
      (lexer->lookahead == '"' || lexer->lookahead == '\'')) {
    int32_t quote = lexer->lookahead;
    lexer->advance(lexer, false);
    while (lexer->lookahead != 0 && !is_newline(lexer->lookahead)) {
      if (lexer->lookahead == quote) {
        lexer->advance(lexer, false);
        break;
      } else if (lexer->lookahead == '\\') {
        lexer->advance(lexer, false);
        if (lexer->lookahead != 0) lexer->advance(lexer, false);
      } else {
        lexer->advance(lexer, false);
      }
    }
    lexer->result_symbol = QUOTED_STRING;
    return true;
  }

// UNQUOTED_STRING
if (valid_symbols[UNQUOTED_STRING]) {
  bool found = false;

  for (;;) {
    int32_t c = lexer->lookahead;

    if (c == 0 || c == ',' || is_newline(c)) break;

    if (c == '/') {
      lexer->advance(lexer, false);

      if (lexer->lookahead == '/') {
        return found
          ? (lexer->result_symbol = UNQUOTED_STRING, true)
          : false;
      }
      found = true;
      lexer->mark_end(lexer);
      continue;
    }

    lexer->advance(lexer, false);
    found = true;
    lexer->mark_end(lexer);
  }

  if (found) {
    lexer->result_symbol = UNQUOTED_STRING;
    return true;
  }
}

  return false;
}
