/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:17:28 by vloddo            #+#    #+#             */
/*   Updated: 2024/11/28 12:17:30 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && c != s[i])
		i++;
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}

#include <stdio.h>
int main()
{
	char s[100] = "ciaooooo";
	char c = 'a';

	char *p = ft_strchr(s, c);
	printf("%s\n", p);
	printf("%p\n", p);
}