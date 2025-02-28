/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:28:58 by vloddo            #+#    #+#             */
/*   Updated: 2025/02/28 13:29:07 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

static int	count_words(const char *s, char c)
{
    int count = 0;
    while (*s)
    {
        while (*s == c) s++;
        if (*s) count++;
        while (*s && *s != c) s++;
    }
    return count;
}

char	**ft_split(const char *s, char c)
{
    char **split;
    int i = 0, j;
    
    if (!s) return NULL;
    
    split = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
    if (!split) return NULL;
    
    while (*s)
    {
        while (*s == c) s++;
        j = 0;
        while (s[j] && s[j] != c) j++;
        if (j > 0)
        {
            split[i] = (char *)malloc(j + 1);
            if (!split[i]) return NULL;
            int k = 0;
            while (k < j) split[i][k++] = *s++;
            split[i++][k] = '\0';
        }
        while (*s && *s == c) s++;
    }
    split[i] = NULL;
    return split;
}
size_t	ft_strlen(const char *a)
{
    size_t	i;

    i = 0;
    while (a[i] != '\0')
        i++;
    return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	final = malloc(sizeof(char) * (i + j + 1));
	if (!final)
		return (NULL);
	final[i + j] = '\0';
	while (j > 0)
	{
		j--;
		final[i + j] = s2[j];
	}
	while (i > 0)
	{
		i--;
		final[i] = s1[i];
	}
	return (final);
}
