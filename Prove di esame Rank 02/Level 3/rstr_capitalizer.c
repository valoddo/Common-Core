#include <unistd.h>

int main(int argc, char **argv)
{

    int i;
    int j;
    if (argc == 1)
    {
        write (1, "\n", 1);
        return(0);
    }
    if (argc >= 2)
    {
        j = 0;
        while (j < argc)
        {
            i = 0;
            while(argv[j][i])
            {
                if (argv[j][i+1] == ' ' || argv[j][i+1] == '\0')
                {
                    if(argv[j][i] >= 'a' && argv[j][i] <= 'z')
                        argv[j][i] = argv[j][i] - 32;
                }
                else if(argv[j][i] >= 'A' && argv[j][i] <= 'Z')
                    argv[j][i] = argv[j][i] + 32;
                write(1, &argv[j][i], 1);
                i++;
            }
            write (1, "\n", 1);
            j++; 
        }
    }
    return(0);
}