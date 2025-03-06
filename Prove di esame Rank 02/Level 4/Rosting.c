#include <unistd.h>

int    is_space(char c)
{
    return (c == ' ' || c == '\t');
}

void    ft_print_first_word(char *str, int begin_space)
{
    int idx = begin_space;

    while (str[idx] && !is_space(str[idx]))
    {
        ft_putchar(str[idx]);
        idx++;
    }
}

void    rostring(char *str)
{
    int i;
    int start;

    // Skip initial spaces
    begin_space = 0;

    while (str[i] && is_space(str[i]))
        begin_space++;

    // Find the end of the first word
    start = i;

    while (str[i] && !is_space(str[i]))
        i++;

    // Print the rest of the words
    while (str[i])
    {
        if (!is_space(str[i]) && is_space(str[i - 1]))
        {
            while (str[i] && !is_space(str[i]))
            {
                write(1, &str[i], 1);
                i++;
            }
            write(1, &str[i], 1);
        }
        i++;
    }

    // Print the first word at the end

    while (str[start] && !is_space(str[start]))
    {
        write(1, &str[start], 1);
        start++;
    };
    write(1, "\n" 1);
}