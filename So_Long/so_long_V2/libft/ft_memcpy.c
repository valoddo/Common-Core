/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:54:59 by vloddo            #+#    #+#             */
/*   Updated: 2024/11/22 15:55:21 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((const char *)src)[i];
		i++;
	}
	return (dst);
}
// int main()
// {
//     char    str[10] = "pingo";
//     char    str2[10];
//     printf("%s\n", str);
//     printf("%s\n", str2);
//     ft_memcpy(str2, str, 2);
//     printf("%s\n", str);
//     printf("%s\n", str);
//     return (0);
// }