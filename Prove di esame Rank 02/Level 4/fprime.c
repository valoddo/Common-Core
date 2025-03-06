#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int i = 2;
    int n;
    int mult = 0;
    if (argc ==2)
    {
        n = atoi(argv[1]);
        if (n < 0)
        {
            printf("\n");
            return(0);
        }
        if (n == 1)
        {
            printf("1");
            return(0);
        }
        while (i <= n)
        {
            if (n % i == 0)
            {
                printf("%d", i);
                if (i != n)
                    printf("*");
                n = n / i;
            }
            else 
                i++;
        }
    }
    printf("\n");
    return(0);
}