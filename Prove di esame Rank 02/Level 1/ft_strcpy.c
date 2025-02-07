/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:58:52 by vloddo            #+#    #+#             */
/*   Updated: 2025/02/04 11:58:54 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;
	
	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

#include <stdio.h>

int main()
{
	char *s1;
	char *s2;
	
	s2 = "Hello World";
	s1 = ft_strcpy(s1, s2);
	printf("%s", s1);
	return (0);
}
