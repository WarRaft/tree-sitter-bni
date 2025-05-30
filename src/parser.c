/* Automatically generated by tree-sitter v0.25.3 */

#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 15
#define STATE_COUNT 30
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 24
#define ALIAS_COUNT 0
#define TOKEN_COUNT 14
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 3
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define MAX_RESERVED_WORD_SET_SIZE 0
#define PRODUCTION_ID_COUNT 4
#define SUPERTYPE_COUNT 0

enum ts_symbol_identifiers {
  sym_newline = 1,
  anon_sym_LBRACK = 2,
  anon_sym_RBRACK = 3,
  anon_sym_EQ = 4,
  sym_comment = 5,
  sym_key = 6,
  anon_sym_COMMA = 7,
  anon_sym_DQUOTE = 8,
  aux_sym_quoted_string_token1 = 9,
  aux_sym_quoted_string_token2 = 10,
  sym_bare_value = 11,
  sym_id = 12,
  sym_whitespace = 13,
  sym_program = 14,
  sym__line = 15,
  sym_section = 16,
  sym_item = 17,
  sym_value_list = 18,
  sym_value = 19,
  sym_quoted_string = 20,
  aux_sym_program_repeat1 = 21,
  aux_sym_value_list_repeat1 = 22,
  aux_sym_quoted_string_repeat1 = 23,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_newline] = "newline",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_EQ] = "=",
  [sym_comment] = "comment",
  [sym_key] = "key",
  [anon_sym_COMMA] = ",",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_quoted_string_token1] = "quoted_string_token1",
  [aux_sym_quoted_string_token2] = "quoted_string_token2",
  [sym_bare_value] = "bare_value",
  [sym_id] = "id",
  [sym_whitespace] = "whitespace",
  [sym_program] = "program",
  [sym__line] = "_line",
  [sym_section] = "section",
  [sym_item] = "item",
  [sym_value_list] = "value_list",
  [sym_value] = "value",
  [sym_quoted_string] = "quoted_string",
  [aux_sym_program_repeat1] = "program_repeat1",
  [aux_sym_value_list_repeat1] = "value_list_repeat1",
  [aux_sym_quoted_string_repeat1] = "quoted_string_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_newline] = sym_newline,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_EQ] = anon_sym_EQ,
  [sym_comment] = sym_comment,
  [sym_key] = sym_key,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_quoted_string_token1] = aux_sym_quoted_string_token1,
  [aux_sym_quoted_string_token2] = aux_sym_quoted_string_token2,
  [sym_bare_value] = sym_bare_value,
  [sym_id] = sym_id,
  [sym_whitespace] = sym_whitespace,
  [sym_program] = sym_program,
  [sym__line] = sym__line,
  [sym_section] = sym_section,
  [sym_item] = sym_item,
  [sym_value_list] = sym_value_list,
  [sym_value] = sym_value,
  [sym_quoted_string] = sym_quoted_string,
  [aux_sym_program_repeat1] = aux_sym_program_repeat1,
  [aux_sym_value_list_repeat1] = aux_sym_value_list_repeat1,
  [aux_sym_quoted_string_repeat1] = aux_sym_quoted_string_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_newline] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_key] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_quoted_string_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_quoted_string_token2] = {
    .visible = false,
    .named = false,
  },
  [sym_bare_value] = {
    .visible = true,
    .named = true,
  },
  [sym_id] = {
    .visible = true,
    .named = true,
  },
  [sym_whitespace] = {
    .visible = true,
    .named = true,
  },
  [sym_program] = {
    .visible = true,
    .named = true,
  },
  [sym__line] = {
    .visible = false,
    .named = true,
  },
  [sym_section] = {
    .visible = true,
    .named = true,
  },
  [sym_item] = {
    .visible = true,
    .named = true,
  },
  [sym_value_list] = {
    .visible = true,
    .named = true,
  },
  [sym_value] = {
    .visible = true,
    .named = true,
  },
  [sym_quoted_string] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_program_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_value_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_quoted_string_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_key = 1,
  field_name = 2,
  field_value = 3,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_key] = "key",
  [field_name] = "name",
  [field_value] = "value",
};

static const TSMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_key, 0},
  [1] =
    {field_name, 1},
  [2] =
    {field_key, 0},
    {field_value, 2},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(9);
      if (lookahead == '"') ADVANCE(21);
      if (lookahead == ',') ADVANCE(19);
      if (lookahead == '/') ADVANCE(7);
      if (lookahead == '=') ADVANCE(15);
      if (lookahead == '[') ADVANCE(13);
      if (lookahead == ']') ADVANCE(14);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(11);
      if (lookahead == '"') ADVANCE(20);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(26);
      if (lookahead != 0 &&
          lookahead != ',') ADVANCE(29);
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(2);
      if (lookahead == '"') ADVANCE(20);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(27);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(27);
      if (lookahead != 0 &&
          lookahead != ',') ADVANCE(29);
      END_STATE();
    case 3:
      if (lookahead == '\n') SKIP(3);
      if (lookahead == '"') ADVANCE(21);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(24);
      if (lookahead != 0) ADVANCE(23);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(12);
      if (lookahead == ',') ADVANCE(19);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(32);
      if ((0x0b <= lookahead && lookahead <= '\r')) SKIP(4);
      END_STATE();
    case 5:
      if (lookahead == '\n') SKIP(5);
      if (lookahead == '"') ADVANCE(20);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(28);
      if (lookahead != 0 &&
          lookahead != ',') ADVANCE(29);
      END_STATE();
    case 6:
      if (lookahead == '\n') SKIP(6);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(30);
      if (lookahead != 0 &&
          lookahead != ';' &&
          lookahead != '=' &&
          lookahead != '[' &&
          lookahead != ']') ADVANCE(31);
      END_STATE();
    case 7:
      if (lookahead == '/') ADVANCE(16);
      END_STATE();
    case 8:
      if (eof) ADVANCE(9);
      if (lookahead == '\n') ADVANCE(10);
      if (lookahead == '/') ADVANCE(17);
      if (lookahead == '[') ADVANCE(13);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      if (lookahead != 0 &&
          lookahead != ';' &&
          lookahead != '=' &&
          lookahead != ']') ADVANCE(18);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_newline);
      if (lookahead == '\n') ADVANCE(10);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_newline);
      if (lookahead == '\n') ADVANCE(11);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(26);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_newline);
      if (lookahead == '\n') ADVANCE(12);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(32);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(16);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(sym_key);
      if (lookahead == '/') ADVANCE(18);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';' &&
          lookahead != '=' &&
          lookahead != '[' &&
          lookahead != ']') ADVANCE(18);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym_key);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';' &&
          lookahead != '=' &&
          lookahead != '[' &&
          lookahead != ']') ADVANCE(18);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      if (lookahead == '"') ADVANCE(25);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ',') ADVANCE(29);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(aux_sym_quoted_string_token1);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(aux_sym_quoted_string_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(24);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '"') ADVANCE(23);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(aux_sym_quoted_string_token2);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym_bare_value);
      if (lookahead == '\n') ADVANCE(11);
      if (lookahead == '"') ADVANCE(22);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(26);
      if (lookahead != 0 &&
          lookahead != ',') ADVANCE(29);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_bare_value);
      if (lookahead == '"') ADVANCE(22);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(27);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(27);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ',') ADVANCE(29);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_bare_value);
      if (lookahead == '"') ADVANCE(22);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(28);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ',') ADVANCE(29);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_bare_value);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ',') ADVANCE(29);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(30);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ';' &&
          lookahead != '=' &&
          lookahead != '[' &&
          lookahead != ']') ADVANCE(31);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_id);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ';' &&
          lookahead != '=' &&
          lookahead != '[' &&
          lookahead != ']') ADVANCE(31);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_whitespace);
      if (lookahead == '\n') ADVANCE(12);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(32);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexerMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 8},
  [2] = {.lex_state = 8},
  [3] = {.lex_state = 8},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 8},
  [6] = {.lex_state = 2},
  [7] = {.lex_state = 2},
  [8] = {.lex_state = 3},
  [9] = {.lex_state = 4},
  [10] = {.lex_state = 3},
  [11] = {.lex_state = 4},
  [12] = {.lex_state = 4},
  [13] = {.lex_state = 5},
  [14] = {.lex_state = 3},
  [15] = {.lex_state = 5},
  [16] = {.lex_state = 4},
  [17] = {.lex_state = 4},
  [18] = {.lex_state = 4},
  [19] = {.lex_state = 4},
  [20] = {.lex_state = 4},
  [21] = {.lex_state = 4},
  [22] = {.lex_state = 8},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 6},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 8},
  [28] = {.lex_state = 8},
  [29] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [STATE(0)] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [sym_comment] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [aux_sym_quoted_string_token2] = ACTIONS(1),
  },
  [STATE(1)] = {
    [sym_program] = STATE(24),
    [sym__line] = STATE(3),
    [sym_section] = STATE(22),
    [sym_item] = STATE(22),
    [aux_sym_program_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_newline] = ACTIONS(5),
    [anon_sym_LBRACK] = ACTIONS(7),
    [sym_comment] = ACTIONS(9),
    [sym_key] = ACTIONS(11),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 7,
    ACTIONS(13), 1,
      ts_builtin_sym_end,
    ACTIONS(15), 1,
      sym_newline,
    ACTIONS(18), 1,
      anon_sym_LBRACK,
    ACTIONS(21), 1,
      sym_comment,
    ACTIONS(24), 1,
      sym_key,
    STATE(2), 2,
      sym__line,
      aux_sym_program_repeat1,
    STATE(22), 2,
      sym_section,
      sym_item,
  [24] = 7,
    ACTIONS(7), 1,
      anon_sym_LBRACK,
    ACTIONS(9), 1,
      sym_comment,
    ACTIONS(11), 1,
      sym_key,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
    ACTIONS(29), 1,
      sym_newline,
    STATE(2), 2,
      sym__line,
      aux_sym_program_repeat1,
    STATE(22), 2,
      sym_section,
      sym_item,
  [48] = 6,
    ACTIONS(31), 1,
      sym_newline,
    ACTIONS(33), 1,
      anon_sym_DQUOTE,
    ACTIONS(35), 1,
      sym_bare_value,
    STATE(9), 1,
      sym_value,
    STATE(16), 1,
      sym_quoted_string,
    STATE(28), 1,
      sym_value_list,
  [67] = 2,
    ACTIONS(37), 2,
      ts_builtin_sym_end,
      sym_newline,
    ACTIONS(39), 3,
      anon_sym_LBRACK,
      sym_comment,
      sym_key,
  [77] = 5,
    ACTIONS(33), 1,
      anon_sym_DQUOTE,
    ACTIONS(35), 1,
      sym_bare_value,
    ACTIONS(41), 1,
      sym_whitespace,
    STATE(16), 1,
      sym_quoted_string,
    STATE(20), 1,
      sym_value,
  [93] = 5,
    ACTIONS(33), 1,
      anon_sym_DQUOTE,
    ACTIONS(35), 1,
      sym_bare_value,
    ACTIONS(43), 1,
      sym_whitespace,
    STATE(16), 1,
      sym_quoted_string,
    STATE(18), 1,
      sym_value,
  [109] = 4,
    ACTIONS(45), 1,
      anon_sym_DQUOTE,
    ACTIONS(47), 1,
      aux_sym_quoted_string_token1,
    ACTIONS(49), 1,
      aux_sym_quoted_string_token2,
    STATE(10), 1,
      aux_sym_quoted_string_repeat1,
  [122] = 4,
    ACTIONS(51), 1,
      sym_newline,
    ACTIONS(53), 1,
      anon_sym_COMMA,
    ACTIONS(55), 1,
      sym_whitespace,
    STATE(12), 1,
      aux_sym_value_list_repeat1,
  [135] = 4,
    ACTIONS(57), 1,
      anon_sym_DQUOTE,
    ACTIONS(59), 1,
      aux_sym_quoted_string_token1,
    ACTIONS(61), 1,
      aux_sym_quoted_string_token2,
    STATE(14), 1,
      aux_sym_quoted_string_repeat1,
  [148] = 4,
    ACTIONS(63), 1,
      sym_newline,
    ACTIONS(65), 1,
      anon_sym_COMMA,
    ACTIONS(68), 1,
      sym_whitespace,
    STATE(11), 1,
      aux_sym_value_list_repeat1,
  [161] = 4,
    ACTIONS(53), 1,
      anon_sym_COMMA,
    ACTIONS(55), 1,
      sym_whitespace,
    ACTIONS(71), 1,
      sym_newline,
    STATE(11), 1,
      aux_sym_value_list_repeat1,
  [174] = 4,
    ACTIONS(33), 1,
      anon_sym_DQUOTE,
    ACTIONS(35), 1,
      sym_bare_value,
    STATE(16), 1,
      sym_quoted_string,
    STATE(20), 1,
      sym_value,
  [187] = 4,
    ACTIONS(73), 1,
      anon_sym_DQUOTE,
    ACTIONS(75), 1,
      aux_sym_quoted_string_token1,
    ACTIONS(78), 1,
      aux_sym_quoted_string_token2,
    STATE(14), 1,
      aux_sym_quoted_string_repeat1,
  [200] = 4,
    ACTIONS(33), 1,
      anon_sym_DQUOTE,
    ACTIONS(35), 1,
      sym_bare_value,
    STATE(16), 1,
      sym_quoted_string,
    STATE(21), 1,
      sym_value,
  [213] = 1,
    ACTIONS(81), 3,
      sym_newline,
      anon_sym_COMMA,
      sym_whitespace,
  [219] = 1,
    ACTIONS(83), 3,
      sym_newline,
      anon_sym_COMMA,
      sym_whitespace,
  [225] = 1,
    ACTIONS(63), 3,
      sym_newline,
      anon_sym_COMMA,
      sym_whitespace,
  [231] = 1,
    ACTIONS(85), 3,
      sym_newline,
      anon_sym_COMMA,
      sym_whitespace,
  [237] = 1,
    ACTIONS(87), 3,
      sym_newline,
      anon_sym_COMMA,
      sym_whitespace,
  [243] = 1,
    ACTIONS(89), 3,
      sym_newline,
      anon_sym_COMMA,
      sym_whitespace,
  [249] = 1,
    ACTIONS(91), 1,
      sym_newline,
  [253] = 1,
    ACTIONS(93), 1,
      anon_sym_EQ,
  [257] = 1,
    ACTIONS(95), 1,
      ts_builtin_sym_end,
  [261] = 1,
    ACTIONS(97), 1,
      sym_id,
  [265] = 1,
    ACTIONS(99), 1,
      anon_sym_RBRACK,
  [269] = 1,
    ACTIONS(101), 1,
      sym_newline,
  [273] = 1,
    ACTIONS(103), 1,
      sym_newline,
  [277] = 1,
    ACTIONS(105), 1,
      anon_sym_COMMA,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 24,
  [SMALL_STATE(4)] = 48,
  [SMALL_STATE(5)] = 67,
  [SMALL_STATE(6)] = 77,
  [SMALL_STATE(7)] = 93,
  [SMALL_STATE(8)] = 109,
  [SMALL_STATE(9)] = 122,
  [SMALL_STATE(10)] = 135,
  [SMALL_STATE(11)] = 148,
  [SMALL_STATE(12)] = 161,
  [SMALL_STATE(13)] = 174,
  [SMALL_STATE(14)] = 187,
  [SMALL_STATE(15)] = 200,
  [SMALL_STATE(16)] = 213,
  [SMALL_STATE(17)] = 219,
  [SMALL_STATE(18)] = 225,
  [SMALL_STATE(19)] = 231,
  [SMALL_STATE(20)] = 237,
  [SMALL_STATE(21)] = 243,
  [SMALL_STATE(22)] = 249,
  [SMALL_STATE(23)] = 253,
  [SMALL_STATE(24)] = 257,
  [SMALL_STATE(25)] = 261,
  [SMALL_STATE(26)] = 265,
  [SMALL_STATE(27)] = 269,
  [SMALL_STATE(28)] = 273,
  [SMALL_STATE(29)] = 277,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0),
  [15] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [18] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(25),
  [21] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(22),
  [24] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(23),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 1, 0, 0),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [31] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_item, 2, 0, 1),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__line, 2, 0, 0),
  [39] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__line, 2, 0, 0),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [49] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [51] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_value_list, 1, 0, 0),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [55] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [57] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [61] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [63] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_value_list_repeat1, 2, 0, 0),
  [65] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_value_list_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [68] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_value_list_repeat1, 2, 0, 0), SHIFT_REPEAT(29),
  [71] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_value_list, 2, 0, 0),
  [73] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_quoted_string_repeat1, 2, 0, 0),
  [75] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(14),
  [78] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(14),
  [81] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_value, 1, 0, 0),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quoted_string, 3, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quoted_string, 2, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_value_list_repeat1, 3, 0, 0),
  [89] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_value_list_repeat1, 4, 0, 0),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [95] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section, 3, 0, 2),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_item, 3, 0, 3),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_bni(void) {
  static const TSLanguage language = {
    .abi_version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .supertype_count = SUPERTYPE_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = (const void*)ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
    .name = "bni",
    .max_reserved_word_set_size = 0,
    .metadata = {
      .major_version = 0,
      .minor_version = 1,
      .patch_version = 0,
    },
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
