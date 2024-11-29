/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:48:27 by vloddo            #+#    #+#             */
/*   Updated: 2024/11/28 17:48:29 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		if (p[i] == (unsigned char) c)
			return ((void *) &p[i]);
		i++;
	}
	return (NULL);
}

#include <stdio.h>
int main()
{
	printf("%s", (char *)ft_memchr("Ciao Valentina",'a',6)); 
}

