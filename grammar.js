module.exports = grammar({
    name: 'bni',

    rules: {
        program: $ => repeat($._line),

        _line: $ => choice(
            seq($.section, $.newline),
            seq($.item, $.newline),
            seq($.comment, $.newline),
            $.newline,
        ),

        newline: _ => /\n/,

        section: $ => seq(
            '[',
            field('name', $.id),
            ']'
        ),

        item: $ => seq(
            field('key', $.key),
            '=',
            field('value', optional($.value_list))
        ),

        comment: _ => token(prec(-1, seq('//', /.*/))),

        key: _ => /[^\s=\[\];][^=\[\];\n]*/,

        value_list: $ => seq(
            $.value,
            repeat(seq(
                optional($.whitespace),
                ',',
                optional($.whitespace),
                $.value
            ))
        ),

        value: $ => choice(
            $.quoted_string,
            $.bare_value
        ),

        quoted_string: _ => seq(
            '"',
            repeat(choice(
                /[^"\n]/,
                /""/
            )),
            '"'
        ),

        bare_value: _ => /[^,"\n][^,\n]*/,

        id: _ => /[^\[\]\n=;]+/,

        whitespace: _ => /[ \t]+/,
    }
})
