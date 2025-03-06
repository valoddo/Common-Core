#include <unistd.h>

int ft_atoi(char *str)
{
    int i = 0;
    int nb = 0;
    int sign = 1;

    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = sign * -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        nb = (nb * 10) + (str[i] - '0');
        i++;
    }
    return (nb * sign);
}
void putnb(int i)
{
    if (i > 9)
        putnb(i / 10);
    write(1, &"0123456789"[i % 10], 1);
}

int main(int argc, char **argv)
{
    int i = 1;
    int a;
    int tab;

    if (argc == 2)
    {
        a = ft_atoi(argv[1]);
        while (i <= 9)
        {
            
            putnb(i);
            write(1, " x ", 3);
            putnb(a);
            write(1, " = ", 3);
            tab = a * i;
            putnb(tab);
            write(1, "\n", 1);
            i++;
        }
    }
    write (1, "\n", 1);
    return(0);
}