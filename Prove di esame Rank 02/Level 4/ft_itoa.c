/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:42:51 by vloddo            #+#    #+#             */
/*   Updated: 2024/12/11 13:42:52 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_char(char *s, unsigned int number, long int len)
{
	while (number > 0)
	{
		s[len--] = 48 + (number % 10);
		number = number / 10;
	}
	return (s);
}

static long int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char				*s;
	long int			len;
	unsigned int		number;
	int					sign;

	sign = 1;
	len = ft_len(n);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!(s))
		return (NULL);
	s[len--] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		sign *= -1;
		number = n * -1;
		s[0] = '-';
	}
	else
		number = n;
	s = ft_char(s, number, len);
	return (s);
}

// int main() 
// {
//     static int num1 = 123;
//     static int num2 = -456;
//     static int num3 = 0;
//     static int num4 = 2147483647;
//     static int num5 = -2147483648;
//     printf("num1 = %d -> ft_itoa: %s\n", num1, ft_itoa(num1));
//     printf("num2 = %d -> ft_itoa: %s\n", num2, ft_itoa(num2));
//     printf("num3 = %d -> ft_itoa: %s\n", num3, ft_itoa(num3));
//     printf("num4 = %d -> ft_itoa: %s\n", num4, ft_itoa(num4));
//     printf("num5 = %d -> ft_itoa: %s\n", num5, ft_itoa(num5));
//     return 0;
// }
