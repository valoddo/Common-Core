#include <unistd.h>

int atoi(char *str)
{
    int i = 0;
    int nb = 0;
    int sign = 1;

    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            return(0);
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        nb = (nb * 10) + (str[i] - '0');
        i++;
    }
    return(nb * sign);
}
void putnb(int i)
{
    if(i >= 16)
        putnb(i / 16);
    write(1, &"0123456789abcdef"[i % 16], 1);
}


int main(int argc, char **argv)
{
    int i;

    if (argc == 2)
    {
        i = atoi(argv[1]);
        putnb(i);
    }
    write(1, "\n", 1);
    return(0);
}