/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:33:49 by vloddo            #+#    #+#             */
/*   Updated: 2024/11/18 14:33:57 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

int	ft_isalpha(int i)
{
	if ((i >= 65 & i <= 90) || (i >= 97 & i <= 122))
	{
		return (0);
	}
	else
		return (1);
}

int	main(void)
{
	printf("%d\n", ft_isalpha('3'));
	return (0);
}
