#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    char *s1;
    char *s2;

    if (argc == 3)
    {
        s1 = argv[1];
        s2 = argv[2];
        while (s2[j] != '\0')
        {
            if (s1[i] == s2[j])
                i++;
            j++;
        }
        if (s1[i] == '\0')
        {
            i = 0;
            while (s1[i])
            {
                write(1, &s1[i], 1);
                i++;
            }
        }
        else
        {
            write(1, "\n", 1);
            return(0);
        }
    }
    write(1, "\n", 1);
    return(0);
}