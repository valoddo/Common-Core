/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:54:59 by vloddo            #+#    #+#             */
/*   Updated: 2024/11/22 15:55:21 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	i;

	i = 0;
	d = dest;
	s = src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((const char *)src)[i]; // cast diretto del puntatore voi ((unsigned char *)dest)[i]
		i++;
	}
	return (dest);
}

int	main(void)
{
	char	str[20] = "Hello World";
	char	final[20];

	printf("before memcpy: %s\n", str);
	ft_memcpy(final, str, 20);
	printf("after memcpy: %s\n", str);
	return (0);
}

