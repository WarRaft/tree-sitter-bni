module.exports = grammar({
    name: 'bni',

    rules: {
        program: $ => repeat($._line),

        _line: $ => choice(
            $.section_line,
            $.key_value_line,
            $.comment_line,
            $.empty_line
        ),

        section_line: $ => seq(
            $.section,
            /\n/
        ),

        key_value_line: $ => seq(
            $.key_value,
            /\n/
        ),

        comment_line: $ => seq(
            $.comment,
            /\n/
        ),

        empty_line: _ => /\n/,

        section: $ => seq(
            '[',
            field('name', $.identifier),
            ']'
        ),

        key_value: $ => seq(
            field('key', $.key),
            '=',
            field('value', optional($.value_list))
        ),

        comment: _ => token(prec(-1, seq('//', /.*/))),

        key: _ => /[^\s=\[\];][^=\[\];\n]*/,

        value_list: $ => seq($.value, repeat(seq(',', $.value))),

        value: $ => choice(
            $.quoted_string,
            $.bare_value
        ),

        quoted_string: _ => seq(
            '"',
            repeat(/[^"\n]/),
            '"'
        ),

        bare_value: _ => /[^,"\n]+/,

        identifier: _ => /[^\[\]\n=;]+/,
    }
})
