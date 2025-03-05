#include <unistd.h>

int ft_atoi(const char *str)
{
    int i;
    int sign;
    int nb;

    i = 0;
    nb = 0;
    sign = 1;

        if (str[i] >= 9 && str[i] <= 13 || str[i] == ' ')
            i++;
        if (str[i] == '+')
            i++;
        else if (str[i] == '-')
        {
            sign = -1;
            i++;
        }
        while (str[i] >= '0' && str[i] <= '9')
        {
            nb = (nb * 10) + (str[i] - '0');
            i++;
        }
    nb = nb * sign;
    return (nb);
}

#include <stdio.h>
int main()
{
    const char a = 123;
    printf("%d", ft_atoi("123"));
    return(0);
}