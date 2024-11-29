/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:49:00 by vloddo            #+#    #+#             */
/*   Updated: 2024/11/28 18:49:02 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*t;

	i = 0;
	p = (unsigned char *)s1;
	t = (unsigned char *)s2;
	while (i < n)
	{
		if (p[i] != t[i])
			return (p[i] - t[i]);
		i++;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>
int	main()
{	
	printf("%d", (int)ft_memcmp("Hello","Z",6));
	printf("%d", (int)memcmp("Hello","Z",6));
}
