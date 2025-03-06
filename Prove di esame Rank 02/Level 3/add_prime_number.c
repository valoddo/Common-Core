#include <unistd.h>

int atoi(char *str)
{
    int i = 0;
    int nb = 0;
    int sign = 1;

    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = - 1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        nb = (nb * 10) + (str[i] - '0');
        i++;
    }
    return (nb * sign);
}

int	is_prime(int n)
{
	int i;

	if (n < 2)
		return (0);
	i = 2;
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}
void putnb(int i)
{
    if (i > 9)
        putnb(i / 10);
    write(1, &"0123456789"[i%10], 1);
}

int main(int argc, char ** argv)
{
    int n;
    int i = 2;
    int sum;

    if (argc == 2)
    {
        n = atoi(argv[1]);
        if (n <= 0)
        {
            write (1, "0\n", 2);
            return(0);        
        }
        sum = 0;
        while (i <= n)
	    {
		    if (is_prime(i))
			    sum = sum + i;
		    i++;
	    }
        putnb(sum);
	    return (0);
    }
    write (1, "0\n", 2);
    return(0);
}