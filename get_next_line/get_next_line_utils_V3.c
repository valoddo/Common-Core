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

char	*ft_substr(char *buffer, int lenline, int lenbuffer)
{
	char *final;
	int	i;

	final = malloc(sizeof(char) * (lenbuffer + 1));
	if (!final)
		return (NULL);
	i = 0;
	while(lenbuffer > 0)
	{
		final[i] = buffer[lenline + i];
		i++;
		lenbuffer--;
	}
	final[i + 1] = '\0';
	return (final);
}

char	*ft_strjoin(char *buffer, char *read_buffer)
{
	char	*final;
	int		i;
	int		j;

	i = ft_strlen(buffer);
	j = ft_strlen(read_buffer);
	final = malloc(sizeof(char) * (i + j + 1));
	if (!final)
		return(NULL);
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
	return	(final);
}


int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while(str[i])
		i++;
	return (i);
}

// int main()
// {
// 	int	fd;
// 	char *str;
// 	char *str2;
// 	char *str3;
// 	char *finaljoin;
// 	char *finalsub;
// 	int	x;
// 	int y;
// 	int	z;
	
// 	str = "ciao";
// 	str2 = "a tutti";
// 	x = ft_strlen(str);
// 	printf("%d\n", x);

// 	finaljoin = ft_strjoin(str, str2);
// 	y = ft_strlen(finaljoin);
// 	printf("%s\n", finaljoin);
// 	printf("%d\n", y);

// 	str3 = "ciao\na tutti";
// 	finalsub = ft_substr(str3, ft_strlen(str), ft_strlen(str3) - (ft_strlen(str)));
// 	z = ft_strlen(finalsub);
// 	printf("%s\n", finalsub);
// 	printf("%d\n", z);
// 	return(0);
// }