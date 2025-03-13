/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:46:07 by vloddo            #+#    #+#             */
/*   Updated: 2024/12/10 14:46:10 by vloddo           ###   ########.fr       */
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

// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	while (src[i])
// 		i++;
// 	if (!size)
// 		return (i);
// 	while (j < size - 1 && src[j])
// 	{
// 		dst[j] = src[j];
// 		j++;
// 	}
// 	dst[j] = '\0';
// 	return (i);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	c = (unsigned char) c;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == c)
// 			return ((char *)&s[i]);
// 		i++;
// 	}
// 	if (c == '\0')
// 		return ((char *)&s[i]);
// 	return (NULL);
// }

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*final;
	int		i;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i > 0 && ft_strchr(set, s1[i - 1]))
		i--;
	final = (char *)malloc(i + 1 * sizeof(char));
	if (!final)
		return (NULL);
	ft_strlcpy(final, (char *)s1, i + 1);
	return (final);
}
// int main()
// {
// 	printf("%s\n", ft_strtrim("Hello ","o"));
// }
