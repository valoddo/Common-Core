/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:45:52 by vloddo            #+#    #+#             */
/*   Updated: 2024/12/10 20:45:53 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;
	int		j;

	i = ft_strlen(s);
	str = (char *)malloc(i + 1 * sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	while (j < i)
	{
		str[j] = (*f)(j, s[j]);
		j++;
	}
	str[j] = '\0';
	return (str);
}
