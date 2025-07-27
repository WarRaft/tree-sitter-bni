module.exports = grammar({
    name: 'bni',

    externals: $ => [
        $.line_break,
    ],

    rules: {
        program: $ => repeat($._line),

        _line: $ => choice(
            $.section,
            $.item,
            $.comment,
            $.blank,
        ),

        section: $ => seq(
            '[',
            field('name', $.section_name),
            ']',
            $.line_break
        ),

        item: $ => seq(
            field('key', optional($.key)),
            '=',
            field('value', optional($.value_list)),
            $.line_break
        ),

        comment: _ => token(prec(-1, seq('//', /.*/))),

        blank: $ => $.line_break,

        key: _ => token(/[^\s=\[\];][^=\[\];\n]*/),

        section_name: _ => /[^\[\]\n=;]+/,

        value_list: $ => repeat1(choice(
            $.comma,
            $.whitespace,
            $.quoted_string,
            $.unquoted_string
        )),

        comma: _ => token(','),

        whitespace: _ => token(/[ \t]+/),

        quoted_string: _ => token(seq(
            '"',
            repeat(choice(/[^"\n]/, /""/)),
            '"'
        )),

        unquoted_string: _ => token(/[^", \t\n][^,\n]*/),
    }
})
