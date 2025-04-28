#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int j = 1;

    if (argc == 1)
    {
        write (1, "\n", 1);
        return(0);
    }
    if (argc >= 2)
    {
        while (j < argc)
        {
            i = 0;
            while (argv[j][i])
            {
                
                if (argv[j][0] >= 'a' && argv[j][0] <= 'z')
                        argv[j][0] = argv[j][0] - 32;
                else if (argv[j][i-1] >= 9 && argv[j][i-1] <= 13 || argv[j][i-1] == ' ' )
                {
                    if (argv[j][i] >= 'a' && argv[j][i] <= 'z')
                        argv[j][i] = argv[j][i] - 32;
                }
                else if (argv[j][i] >= 'A' && argv[j][i] <= 'Z')
                    argv[j][i] = argv[j][i] + 32;
                write(1, &argv[j][i], 1);
                i++;
            }
            write(1, "\n", 1);
            j++;
        }
    }
    return(0);
}