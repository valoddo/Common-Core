/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:58:10 by vloddo            #+#    #+#             */
/*   Updated: 2024/11/29 14:58:13 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;

	if (!little)
        return ((char *)big);
	while (i < len && !big)
	{
		if (big[i] == little[i])
		{
			while (big[i] == little[i])
			{
				i++;
			}
			return ((char *)little);
		}
		i++;
	}
	return (NULL);
}

#include <stdio.h>
#include <string.h>
int	main()
{
	char big[20] = "Hello World";
	char little[10] = "World";

	printf("%d", (int)ft_strnstr("Hello","Z",6));
	printf("%d", (int)strnstr("Hello","Z",6));
}