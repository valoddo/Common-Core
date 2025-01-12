/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:03:43 by bpalchet          #+#    #+#             */
/*   Updated: 2024/12/22 17:03:47 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *str, int value, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = str;
	i = 0;
	while (i < n)
	{
		ptr[i] = value;
		i++;
	}
	return (ptr);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned char	c1;

	c1 = (unsigned char) c;
	if (c1 == '\0')
	{
		while (*str != '\0')
			str++;
		return ((char *)str);
	}
	while (*str != '\0')
	{
		if (*str == c1)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		slen1;
	int		slen2;
	int		i;
	char	*concat;

	slen1 = ft_strlen((char *)s1);
	slen2 = ft_strlen((char *)s2);
	concat = malloc((slen1 + slen2 + 1) * sizeof(char));
	if (concat == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		concat[i] = *s2;
		i++;
		s2++;
	}
	concat[i] = '\0';
	return (concat);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (ptr);
	ptr = ft_memset(ptr, 0, total_size);
	return (ptr);
}
