#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int s1;
    int s2;

    if (argc == 3)
    {
        s1 = atoi(argv[1]);
        s2 = atoi(argv[2]);

        if (s1 > 0 && s2 > 0)
        {
            while (s1 != s2)
            {
                if(s1 > s2)
                    s1 = s1 - s2;
                else 
                    s2 = s2 - s1;
            }
            printf("%d", s1);
        }
    }
    printf(" ");
    return(0);
}

