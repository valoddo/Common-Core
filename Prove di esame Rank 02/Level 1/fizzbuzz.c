/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:15:56 by vloddo            #+#    #+#             */
/*   Updated: 2025/02/01 16:15:59 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int	main()
{
	int	i;
	char	a;
	
	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_putnbr(i);
		write(1, "\n", 1);			
		i++;
	}
	return (0);
}
