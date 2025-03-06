#include <unistd.h>

int is_space(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

int main(int argc, char **argv)
{
    int i = 0;
    int start;
    int end = 0;
    char *s1;

    if (argc == 2)
    {
        s1 = argv[1];
        while (s1[i] && is_space(s1[i]))
            i++;
        start = i;
        while (s1[i] && !is_space(s1[i]))
            i++;
        end = i;
        while (s1[i] && is_space(s1[i]))
            i++;
        while (s1[i])
        {
                write(1, &s1[i], 1);
                i++;
                while (s1[i] == ' ' && s1[i+1] == ' ')
                    i++;
        }
        if (end > start)
        {
            write(1, " ", 1);
            while (s1[start] && !is_space(s1[start]))
            {
                write(1, &s1[start], 1);
                start++;
            }
        }
    }
    write(1, "\n", 1);
    return 0;
}
