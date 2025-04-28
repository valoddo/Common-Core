#include <unistd.h>

unsigned int lcm(unsigned int a, unsigned int b)
{
    unsigned int i;
     if (a == 0 || b == 0)
        return(0);
    if (a > b)
        i = a;
    else
        i = b;
    while (1)
    {
        if ((i % a == 0) && (i % b == 0))
            return (i);
        i++;
    }
}

// Un-comment the following to test
// #include <stdio.h>
// #include <stdlib.h>
// int main(int ac, char **av)
// {
// 	if (ac == 3)
// 	{
// 		unsigned int m = lcm(atoi(av[1]), atoi(av[2]));
// 		printf("LCM: %u\n", m);
// 	}
// }