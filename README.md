[![](https://dcbadge.limes.pink/api/server/https://discord.gg/CNeQmXAgVq)](https://discord.gg/CNeQmXAgVq)

# tree-sitter-bni

A [Tree-sitter](https://tree-sitter.github.io/) grammar for the **BNI** (Blizzard INI) format — a variant of the INI
configuration format used in classic Blizzard games such as *Warcraft III*.

These files are found throughout the game's data, including `TriggerData.txt`, `TriggerStrings.txt`,
`WorldEditStrings.txt`, `MiscData.txt`, `WorldEditData.txt`, and many more.

## Format Overview

A BNI file is a **line-oriented** text format. Each line is one of:

- A **section header** — `[SectionName]`
- A **key-value item** — `Key=value`
- A **comment** — `// ...`
- An **empty line**

### Sections

Sections group related key-value pairs. A section header is a name enclosed in square brackets:

```ini
[TriggerCategories]
[Blight]
[Camera]
```

The closing `]` is optional — the parser accepts `[Section` as well.

### Items (Key-Value Pairs)

Each item is a single line of the form `Key=value`:

```ini
WESTRING_APPNAME=Warcraft III World Editor
FadeBuffMinDuration=10
GoldTextColor=255,255,220,0
```

The key is everything before the first `=`. The value is everything after it.
Both the key and the value are optional:

| Syntax    | Meaning                 |
|-----------|-------------------------|
| `Key=val` | Key with a value        |
| `Key=`    | Key with an empty value |
| `=val`    | No key, just a value    |
| `=`       | Bare equals sign        |

### Comments

Comments start with `//` and extend to the end of the line. They can appear as standalone
lines or inline after a value:

```ini
// This is a standalone comment
//***************************************************************************

PuffDuration=3000 // Duration of a puff, in milliseconds
SpeedVerySlow=175   // lower bound
```

## Value Types

Values are parsed into typed tokens:

| Type              | Examples                              | Description                                |
|-------------------|---------------------------------------|--------------------------------------------|
| `int`             | `42`, `-1`, `0`                       | Integer (optional leading `-`)             |
| `float`           | `0.5`, `-3.14`, `0.00`               | Decimal number (optional leading `-`)      |
| `unquoted_string` | `Warcraft III`, `TerrainArt\Blight`   | Plain text (no commas or quotes)           |
| `quoted_string`   | `"City Building (Diagonal 1, Red)"`   | Text enclosed in `"` or `'`               |
| `comma`           | `,`                                   | Value separator                            |
| `whitespace`      | ` ` / `\t`                            | Significant whitespace (before a comment)  |
| `line_comment`    | `// text`                             | Inline comment at end of value             |

### Whitespace Is Significant

Whitespace tokens are **only** emitted when they appear between a value and an inline comment.
This is by design — it lets editors and highlighters distinguish the gap before a comment from
the value itself:

```
PuffDuration=3000 // Duration
                 ^^^^^^^^^
                 whitespace token
```

Whitespace inside unquoted string values is part of the `unquoted_string` token — it is not
separated out.

### Comma Mechanics

Commas act as **value separators**, splitting a value line into a flat list of typed tokens.
Each element between commas is independently parsed as `int`, `float`, `unquoted_string`, or
`quoted_string`:

```ini
GoldTextColor=255,255,220,0          → int, comma, int, comma, int, comma, int
GoldTextVelocity=0,0.03,100         → int, comma, float, comma, int
abilcode=0,1,1,WESTRING,integer     → int, comma, int, comma, int, comma, unquoted_string, comma, unquoted_string
```

### Quoted Strings

When a value contains a comma that should **not** be treated as a separator, it must be
wrapped in double quotes. The quotes are parsed as **separate tokens** from the content:

```ini
Name="City Building (Diagonal 1, Red)"
```

Tree:

```
(quoted_string
  (string_content))        ← only the text between the quotes
```

The `"` characters are anonymous nodes in the syntax tree. Single quotes (`'`) are also supported.

Empty quoted strings (`""`) are valid — the `string_content` node is simply absent.

This quoting mechanism is commonly used in `TriggerStrings.txt` where display text is mixed
with parameter references (prefixed with `~`):

```ini
FuncKey=~Player," ",~Presses/Releases," the ",~Key," key"
```

Parsed as:

```
(value_list
  (unquoted_string)       ← ~Player
  (comma)
  (quoted_string
    (string_content))     ← " "
  (comma)
  (unquoted_string)       ← ~Presses/Releases
  (comma)
  (quoted_string
    (string_content))     ← " the "
  (comma)
  (unquoted_string)       ← ~Key
  (comma)
  (quoted_string
    (string_content)))    ← " key"
```

## Syntax Tree Structure

```
program
├── section
│   ├── whitespace?       (leading indentation)
│   ├── l_bracket         ([)
│   └── section_name      (text between brackets)
├── item
│   ├── key               (everything before =)
│   └── value_list
│       ├── int
│       ├── float
│       ├── unquoted_string
│       ├── quoted_string
│       │   └── string_content
│       ├── comma
│       ├── whitespace
│       └── line_comment
├── comment
│   ├── whitespace?
│   └── line_comment
└── line_break
```

## Editor Support

The grammar can be used with any editor that supports Tree-sitter:

- [VSCode](https://code.visualstudio.com/) —
  via [JASS-Tree-sitter-Rust](https://github.com/WarRaft/JASS-Tree-sitter-Rust)
- [Neovim](https://neovim.io/) — with Tree-sitter integration (e.g. via `nvim-treesitter`)
- [Zed](https://zed.dev/) — native Tree-sitter support
- [Helix](https://helix-editor.com/) — built-in Tree-sitter highlighting
- [Lapce](https://lapce.dev/) — Tree-sitter-powered highlighting engine

## Development

```sh
# Generate the parser
tree-sitter generate

# Run tests
tree-sitter test

# Build WASM and open playground
tree-sitter build --wasm
tree-sitter playground
```

## License

See [LICENSE](LICENSE).
