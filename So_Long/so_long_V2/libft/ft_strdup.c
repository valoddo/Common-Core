/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:01:30 by vloddo            #+#    #+#             */
/*   Updated: 2024/12/03 11:01:32 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlen(const char *a)
// {
// 	size_t	i;

// 	i = 0;
// 	while (a[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// void	*ft_memset(void *s, int c, size_t n)
// {
// 	unsigned char	*p;
// 	unsigned int	i;

// 	i = 0;
// 	p = s;
// 	while (i < n)
// 	{
// 		p[i] = (unsigned char)c;
// 		i++;
// 	}
// 	return (s);
// }

// void	*ft_calloc(size_t num, size_t size)
// {
// 	size_t	total_size;
// 	void	*ptr;

// 	total_size = num * size;
// 	if (num != 0 && total_size / num != size)
// 		return (NULL);
// 	ptr = malloc(total_size);
// 	if (!ptr)
// 		return (NULL);
// 	ft_memset(ptr, 0, total_size);
// 	return (ptr);
// }

char	*ft_strdup(const char *s)
{
	char	*c;
	size_t	i;

	i = ft_strlen(s);
	c = (char *)ft_calloc(i + 1, sizeof(char));
	if (c != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			c[i] = s[i];
			i++;
		}
		c[i] = '\0';
		return ((char *)c);
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	printf("Mio: %s\n", ft_strdup("H"));
// 	printf("Original: %s\n", (char *)strdup("H"));
// }
