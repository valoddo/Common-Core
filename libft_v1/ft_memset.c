/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:53:20 by vloddo            #+#    #+#             */
/*   Updated: 2024/11/18 18:53:24 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = s;
	while (i < n)
	{
		p[i] = (unsigned char )c;
		i++;
	}
	return (s);
}

// int	main()
// {
// 	char str[50] = "Ciao";
// 	printf("Mio: %s\n", (unsigned char *)ft_memset(str, 'C', 2));
// 	printf("Original: %s\n", (unsigned char *)memset(str, 'C', 2));
// }