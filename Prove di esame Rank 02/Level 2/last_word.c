#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int end;

    i = 0;
    if (argc ==2)
    {
        while (argv[1][i])
            i++;
        i--;
        while (i >= 0 && (argv[1][i] == ' ' || (argv[1][i] >= 9 && argv[1][i] <= 13)))
            i--;
        end = i;
        while (i >= 0 && argv[1][i] != ' ')
            i--;
        while (i++ <= end)
        {
            write(1, &argv[1][i], 1);
        }
    }
    write (1, "\n", 1);
    return (0);
}