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

#include <stdlib.h>
#include <stdio.h>

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

char	*ft_itoa(int nbr)
{
	int		len;
	char	*str;
	long	n;

	n = nbr;
	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (len--)
	{
		if (str[len] == '-')
			break;
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
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
