/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:23:53 by vloddo            #+#    #+#             */
/*   Updated: 2024/11/28 14:23:55 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_int(const char *a)
{
	int	i;

	i = 0;
	while (a[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen_int(s);
	while (i >= 0 && (unsigned char)c != s[i])
		i--;
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}

// #include <stdio.h>

// int main()
// {
// 	printf("Risultato: %s\n", ft_strrchr("teste",'e'));
// }