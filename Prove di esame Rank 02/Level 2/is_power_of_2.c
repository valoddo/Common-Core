#include <unistd.h>

int	    is_power_of_2(unsigned int n)
{
    unsigned long int i;

    i = 1;
    while (i <= n)
    {
        if (i == n)
            return (1); 
        i = i *2;
    }
    return (0);
}

#include <stdio.h>

int main()
{
    unsigned int a;
    a = 32;
    printf ("%d", is_power_of_2(a));
    return(0);
}