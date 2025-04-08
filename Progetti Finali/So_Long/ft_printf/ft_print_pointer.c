/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:58:11 by vloddo            #+#    #+#             */
/*   Updated: 2025/01/09 18:58:26 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(unsigned long p)
{
	unsigned long	i;
	int				j;
	int				c;

	i = 1;
	if (!p)
		return (write(1, "(nil)", 5), 5);
	while (p / i > 15)
		i *= 16;
	j = 2;
	write(1, "0x", 2);
	while (i > 0)
	{
		c = (p / i);
		p %= i;
		write(1, &"0123456789abcdef"[c], 1);
		i /= 16;
		j++;
	}
	return (j);
}
