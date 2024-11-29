/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:00:18 by vloddo            #+#    #+#             */
/*   Updated: 2024/11/22 15:00:22 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	unsigned int	i;

	i = 0;
	p = s;
	if (!s)
		return ;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}
