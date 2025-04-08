/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:00:19 by vloddo            #+#    #+#             */
/*   Updated: 2025/01/09 19:00:31 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		if (str == 'x')
			write(1, &"0123456789abcdef"[c], 1);
		else if (str == 'X')
			write(1, &"0123456789ABCDEF"[c], 1);
		i /= 16;
		j++;
	}
	return (j);
}
