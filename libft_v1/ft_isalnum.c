/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:26:49 by vloddo            #+#    #+#             */
/*   Updated: 2024/11/28 12:07:06 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_isalpha(int i)
// {
// 	if ((i >= 65 & i <= 90) || (i >= 97 & i <= 122))
// 	{
// 		return (1);
// 	}
// 	else
// 		return (0);
// }

// int	ft_isdigit(int i)
// {
// 	if ((i >= 48) && (i <= 57))
// 	{
// 		return (1);
// 	}
// 	else
// 		return (0);
// }

int	ft_isalnum(int i)
{
	if (ft_isalpha(i) || ft_isdigit(i))
	{
		return (1);
	}
	return (0);
}
// int main()
// {
// 	printf("Mio: %d\n", ft_isalnum(300));
// 	printf("Original: %d\n", isalnum(300));
// }