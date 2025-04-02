/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:19:41 by vloddo            #+#    #+#             */
/*   Updated: 2025/03/12 16:19:42 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && (s1[i] == s2[i]))
	{
		i++;
	}
	return (unsigned char)(s1[i]) - (unsigned char)(s2[i]);
}
char	*ft_strcpy(char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

void	*ft_calloc(size_t num, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = num * size;
	if (num != 0 && total_size / num != size)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = s;
	while (i < n)
	{
		p[i] = (unsigned char )c;
		i++;
	}
	return (s);
}
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