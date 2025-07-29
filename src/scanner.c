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
  COMMENT,
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

    enum TokenKind {
        TOKEN_ = 0,
        TOKEN_WS,
        TOKEN_SECTION,
        TOKEN_ITEM
    };
    // enum TokenKind kind = TOKEN_;

  // START OF LINE: SECTION vs ITEM
  if (valid_symbols[WHITESPACE] && valid_symbols[L_BRACKET] && valid_symbols[KEY]) {
    bool eat_ws = false;

    while (lexer->lookahead == ' ' || lexer->lookahead == '\t' ) {
      lexer->advance(lexer, false);
      eat_ws = true;
    }

    if (lexer->lookahead == '[') {
        if (eat_ws){
            lexer->result_symbol = WHITESPACE;
        } else {
            lexer->advance(lexer, false);
            lexer->result_symbol = L_BRACKET;
        }
        lexer->mark_end(lexer);
        return true;
    }


    const int32_t first = lexer->lookahead;
    if (first == '=' || is_newline(first) || lexer->eof(lexer)) {
        return false;
    }

    bool eat_key = false;

    while (!lexer->eof(lexer) && lexer->lookahead != '=' && !is_newline(lexer->lookahead)) {
        lexer->advance(lexer, false);
        eat_key = true;
    }

    if (!eat_key) return false;

    if (lexer->lookahead == '=') {
        lexer->result_symbol = KEY;
    } else {
        lexer->result_symbol = UNQUOTED_STRING;
    }

    lexer->mark_end(lexer);
    return true;
  }

  // WHITESPACE (in value_list)
  if (valid_symbols[WHITESPACE]) {
    if (lexer->lookahead == ' ' || lexer->lookahead == '\t') {
      while (lexer->lookahead == ' ' || lexer->lookahead == '\t') {
        lexer->advance(lexer, true);
      }
      lexer->result_symbol = WHITESPACE;
      return true;
    }
  }

  // COMMA
  if (valid_symbols[COMMA] && lexer->lookahead == ',') {
    lexer->advance(lexer, false);
    lexer->result_symbol = COMMA;
    return true;
  }

  // COMMENT
  if (valid_symbols[COMMENT] && lexer->lookahead == '/') {
    lexer->advance(lexer, false);
    if (lexer->lookahead == '/') {
      lexer->advance(lexer, false);
      while (lexer->lookahead && !is_newline(lexer->lookahead)) {
        lexer->advance(lexer, false);
      }
      lexer->result_symbol = COMMENT;
      return true;
    }
  }

  // INT / FLOAT
  if ((valid_symbols[INT] || valid_symbols[FLOAT]) &&
      (lexer->lookahead == '-' || lexer->lookahead == '.' || (lexer->lookahead >= '0' && lexer->lookahead <= '9'))) {

    int32_t c = lexer->lookahead;
    bool has_leading_digits = false;
    bool has_dot = false;
    bool has_trailing_digits = false;

    if (c == '-') {
      lexer->advance(lexer, false);
      c = lexer->lookahead;
    }

    while (c >= '0' && c <= '9') {
      has_leading_digits = true;
      lexer->advance(lexer, false);
      c = lexer->lookahead;
    }

    if (c == '.') {
      has_dot = true;
      lexer->advance(lexer, false);
      c = lexer->lookahead;
      while (c >= '0' && c <= '9') {
        has_trailing_digits = true;
        lexer->advance(lexer, false);
        c = lexer->lookahead;
      }

      if (c == '.') return false; // более одной точки → ошибка
    }

    if (has_dot && (has_leading_digits || has_trailing_digits) && valid_symbols[FLOAT]) {
      lexer->result_symbol = FLOAT;
      return true;
    }

    if (!has_dot && has_leading_digits && valid_symbols[INT]) {
      lexer->result_symbol = INT;
      return true;
    }

    return false; // fallback → unquoted_string
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
    while (lexer->lookahead != 0 &&
           lexer->lookahead != ',' &&
           !is_newline(lexer->lookahead)) {
      if (lexer->lookahead == '/') {
        lexer->advance(lexer, false);
        if (lexer->lookahead == '/') break;
        found = true;
      } else {
        lexer->advance(lexer, false);
        found = true;
      }
    }
    if (found) {
      lexer->result_symbol = UNQUOTED_STRING;
      return true;
    }
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

  return false;
}
