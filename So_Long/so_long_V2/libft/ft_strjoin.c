/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:51:58 by vloddo            #+#    #+#             */
/*   Updated: 2024/12/10 11:52:00 by vloddo           ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	final = (char *)malloc(sizeof(char) * (i + j + 1));
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

// int main()
// {
// 	printf("%s\n", ft_strjoin("Hello ","World"));
// }
