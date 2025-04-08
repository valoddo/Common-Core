/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:04:00 by vloddo            #+#    #+#             */
/*   Updated: 2025/01/13 13:04:02 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_newline(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_substr_get(char *buffer, int lenline, int lenbuffer)
{
	char	*final;
	int		i;

	if (lenline >= ft_strlen_get(buffer))
		return (NULL);
	final = ft_calloc_get((lenbuffer + 1), sizeof(char));
	if (!final)
		return (NULL);
	i = 0;
	while (i < lenbuffer)
	{
		final[i] = buffer[lenline + i];
		i++;
	}
	final[i] = '\0';
	return (final);
}

char	*ft_strjoin_get(char *buffer, char *read_buffer)
{
	char	*final;
	int		i;
	int		j;

	if (!buffer)
		buffer = "";
	i = ft_strlen_get(buffer);
	j = ft_strlen_get(read_buffer);
	final = ft_calloc_get((i + j + 1), sizeof(char));
	if (!final)
		return (NULL);
	final[i + j] = '\0';
	while (j > 0)
	{
		j--;
		final[i + j] = read_buffer[j];
	}
	while (i > 0)
	{
		i--;
		final[i] = buffer[i];
	}
	return (final);
}

int	ft_strlen_get(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
