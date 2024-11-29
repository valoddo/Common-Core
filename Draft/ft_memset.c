/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:53:20 by vloddo            #+#    #+#             */
/*   Updated: 2024/11/18 18:53:24 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 
#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned int	i;

	i = 0;
	p = s;
	if (!s)
                return (0);
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

int	main(void)
{
	char str[20] = "Hello World";
	printf("before memset: %s\n", str);
	ft_memset(str, '*', 7);
	printf("after memset: %s\n", str);
	return (0);
}
