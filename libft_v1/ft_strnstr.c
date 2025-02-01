/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:58:10 by vloddo            #+#    #+#             */
/*   Updated: 2024/11/29 14:58:13 by vloddo           ###   ########.fr       */
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

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little || !big)
		return ((char *)big);
	if (big && big[0] == '\0' && little[0] == '\0')
		return ((char *)big);
	while (i <= len && big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] != '\0' && \
		little[j] != '\0' && i + j < len)
		{
			j++;
		}
		if (little[j] == '\0')
		{
			return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	printf("Mia: %p\n", ft_strnstr("", "", 9));
// 	//printf("Original: %d\n", strnstr("MZIRIBMZIRIBMZE123", "MZIRIBMZE", 9));

// }