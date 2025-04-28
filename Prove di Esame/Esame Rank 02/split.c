/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:32:03 by vloddo            #+#    #+#             */
/*   Updated: 2025/02/28 15:32:05 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_split(char const *s, char c)
{
	int			words;
	int			in_word;
	const char	*temp;
	char		**dest;

	if (!s)
		return (NULL);
	words = 0;
	in_word = 0;
	temp = s;
	while (*temp)
	{
		if (*temp != c && !in_word && (in_word = 1))
			words++;
		else if (*temp == c)
			in_word = 0;
		temp++;
	}
	dest = (char **)malloc(sizeof(char *) * (words + 1));
	if (!dest)
		return (NULL);
	return (fill_split(dest, s, c, words));
}

static char	**fill_split(char **dest, const char *s, char c, int words)
{
	int	i;
	int	j;
	int	len;
	int	k;

	i = 0;
	j = 0;
	while (i < words)
	{
		while (s[j] == c)
			j++;
		len = 0;
		while (s[j + len] != c && s[j + len] != '\0')
			len++;
		dest[i] = (char *)malloc(len + 1);
		if (!dest[i])
		{
			k = -1;
			while (++k < i)
				free(dest[k]);
			free(dest);
			return (NULL);
		}
		k = -1;
		while (++k < len)
			dest[i][k] = s[j + k];
		dest[i][k] = '\0';
		j += len;
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
