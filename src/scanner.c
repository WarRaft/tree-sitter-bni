#include <tree_sitter/parser.h>
#include <wctype.h>

enum TokenType {
  LINE_BREAK,
};

void *tree_sitter_bni_external_scanner_create() {
  return NULL;
}

void tree_sitter_bni_external_scanner_destroy(void *payload) {
  // No state to destroy
}

unsigned tree_sitter_bni_external_scanner_serialize(void *payload, char *buffer) {
  return 0;
}

void tree_sitter_bni_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
  // No state to deserialize
}

bool tree_sitter_bni_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
  while (iswspace(lexer->lookahead) && lexer->lookahead != '\n') {
    lexer->advance(lexer, true);
  }

  if (lexer->lookahead == '\n') {
    lexer->advance(lexer, false);
    lexer->result_symbol = LINE_BREAK;
    return true;
  }

  return false;
}
