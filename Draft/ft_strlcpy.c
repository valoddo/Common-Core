/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:31:03 by vloddo            #+#    #+#             */
/*   Updated: 2024/11/24 14:49:34 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i = 0;
	size_t j = 0;

	if (!src)
		return (0);
	while (src[i])
		i++;
	while (j < size - 1 && src[j])
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i+1);
}

int	main(void)
{
	const char str[20] = "Hello World";
	char dst;
	printf("after strlcopy: %zu\n",ft_strlcpy(&dst, str, 7));
	return (0);
}
