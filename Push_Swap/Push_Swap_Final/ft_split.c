/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:29:15 by vloddo            #+#    #+#             */
/*   Updated: 2024/12/11 13:29:17 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	word_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] != c) && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*s0_fill(char *s)
{
	int		i;
	char	*word;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	word = ft_calloc((i + 1), sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i])
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	*word_fill(char *s, char c, int *i)
{
	int		j;
	char	*word;

	if (!s)
		return (NULL);
	j = 0;
	while (s[*i] == c)
		(*i)++;
	while (s[*i + j] && s[*i + j] != c)
		j++;
	word = ft_calloc((j + 1), sizeof(char));
	if (!word)
		return (NULL);
	j = 0;
	while (s[*i] && s[*i] != c)
	{
		word[j] = s[*i];
		j++;
		(*i)++;
	}
	word[j] = '\0';
	return (word);
}

static void	free_memory(char **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free (array[i]);
		i++;
	}
	free (array);
}

char	**ft_split(char const *s0, char const *s1, char c)
{
	int		i;
	int		j;
	int		word;
	char	**new_array;

	i = 0;
	word = word_count((char *)s1, c);
	new_array = ft_calloc((word + 2), sizeof(char *));
	if (!new_array)
		return (NULL);
	j = 0;
	while (j <= word)
	{
		if (j == 0)
			new_array[j] = s0_fill((char *)s0);
		else
			new_array[j] = word_fill((char *)s1, c, &i);
		if (!new_array[j])
			return (free_memory(new_array, j), NULL);
		j++;
	}
	new_array[j] = (NULL);
	return (new_array);
}
