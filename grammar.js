module.exports = grammar({
    name: 'bni',

    externals: $ => [
        $.line_break,
        $.l_bracket,
        $.int,
        $.float,
        $.quoted_string,
        $.unquoted_string,
        $.whitespace,
        $.comma,
        $.line_comment,
        $.section_name,
        $.key,
    ],

    rules: {
        program: $ => repeat($._line),

        _line: $ => choice(
            seq($.section, $.line_break),
            seq($.item, $.line_break),
            $.line_break,
        ),

        section: $ => seq(
            optional($.whitespace),
            $.l_bracket,
            $.section_name,
            optional(']'),
        ),

        item: $ => choice(
            seq($.key, '=', $.value_list),
            seq($.key, '='),
            seq('=', $.value_list),
            '='
        ),

        value_list: $ => repeat1(choice(
            seq($.int, optional($.whitespace)),
            seq($.float, optional($.whitespace)),
            seq($.quoted_string, optional($.whitespace)),
            $.unquoted_string,
            $.comma,
            $.line_comment,
        )),
    }
})
