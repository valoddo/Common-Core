/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:31:21 by vloddo            #+#    #+#             */
/*   Updated: 2024/11/23 21:31:28 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = (ft_strlen(dst));
	if (size <= i)
	        return (size + ft_strlen(src)); 

	while (i+j < size - 1 && src[j] != '\0')
	{
		dst[i+j] = src[j];
		j++;
	}
		
	dst[i+j] = '\0';
	return (i + ft_strlen(src));
}


size_t	ft_strlen(const char *a)
{
	size_t	i;

	i = 0;
	while (a[i] != '\0')
	{
		i++;
	}
	return (i);
}


int	main(void)
{
	char dst[20] = "abcde";
	const char str[30] = "bckkkjijlipip;i";
	printf("strlcat result: %zu\n",ft_strlcat(dst, str, 10));
	printf("strlcat stringa: %s\n", dst);
	return (0);
}
