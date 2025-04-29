#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

int ft_printarg(const char *str, va_list arg);
int ft_print_str(char *s);
int ft_print_int(int d);
int ft_print_hexa(char str, unsigned int x);

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;

	va_start(arg, str);
	i = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			i += ft_printarg(str, arg);
		}
		else
		{
			write(1, str, 1);
			i++;
		}
		str++;
	}
	va_end(arg);
	return (i);
}

int	ft_printarg(const char *str, va_list arg)
{
	int	i;

	i = 0;
	if (*str == 's')
		i += ft_print_str(va_arg(arg, char *));
	else if (*str == 'd')
		i += ft_print_int(va_arg(arg, int));
	else if (*str == 'x')
		i += ft_print_hexa(*str, va_arg(arg, unsigned int));
	else if (*str == '%')
	{
		write(1, "%", 1);
		i++;
	}
	return (i);
}

int	ft_print_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6), 6);
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_int(int d)
{
	int	i;
	int	j;

	if (d == -2147483648)
		return (write(1, "-2147483648", 11), 11);
	j = 0;
	if (d < 0)
	{
		write(1, "-", 1);
		d = d * -1;
		j++;
	}
	i = 1;
	while (d / i > 9)
		i *= 10;
	while (i > 0)
	{
		write(1, &"0123456789"[d / i], 1);
		d %= i;
		i /= 10;
		j++;
	}
	return (j);
}

int	ft_print_hexa(char str, unsigned int x)
{
	int	i;
	int	j;
	int	c;

	i = 1;
	while (x / i > 15)
		i *= 16;
	j = 0;
	while (i > 0)
	{
		c = (x / i);
		x %= i;
		write(1, &"0123456789abcdef"[c], 1);
		i /= 16;
		j++;
	}
	return (j);
}

int	 main()
{
	ft_printf("%s\n", "test ft_printf");
	printf("%s\n", "originale printf");
	return(0);
}
