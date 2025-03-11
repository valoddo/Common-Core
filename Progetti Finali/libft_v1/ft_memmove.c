/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:26:53 by vloddo            #+#    #+#             */
/*   Updated: 2024/11/22 17:26:59 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		return (ft_memcpy(dst, src, n));
	}
	while (n--)
	{
		(((unsigned char *)dst)[n] = ((const char *)src)[n]);
	}
	return (dst);
}
