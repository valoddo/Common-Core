/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:20:03 by vloddo            #+#    #+#             */
/*   Updated: 2025/03/05 13:20:04 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int atoi_b(char *str, int base)
{
    int n;
    int sign;
    int i;
    int c;
    
    if (!str || base < 2 || base > 16)
        return 0;
    i = 0;
    sign = 1;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    n = 0;
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            c = str[i] - '0';
        else if (str[i] >= 'A' && str[i] <= 'F')
            c = str[i] - 'A' + 10;
        else if (str[i] >= 'a' && str[i] <= 'f')
            c = str[i] - 'a' + 10;
        else
            return (n * sign);
        if (c >= base)
            return (n * sign);
        n = n * base + c;
        i++;
    }
    return (n * sign);
}

#include <stdio.h>


int main(void)
{
    printf("Test base 10: %d\n", ft_atoi_base("123", 10));  // 123
    printf("Test base 10 (negativo): %d\n", ft_atoi_base("-123", 10));  // -123
    printf("Test base 16: %d\n", ft_atoi_base("A3", 16));  // 163
    printf("Test base 16 (minuscole): %d\n", ft_atoi_base("a3", 16));  // 163
    printf("Test base 2: %d\n", ft_atoi_base("1011", 2));  // 11
    printf("Test base 8: %d\n", ft_atoi_base("77", 8));  // 63
    printf("Test base 16 con segno: %d\n", ft_atoi_base("-1F", 16));  // -31
    printf("Test base 5: %d\n", ft_atoi_base("321", 5));  // 3*5^2 + 2*5^1 + 1 = 86
    printf("Test con spazi: %d\n", ft_atoi_base("   42", 10));  // 42
    printf("Test con caratteri non validi: %d\n", ft_atoi_base("123G", 16));  // 123 (ferma alla G)
    printf("Test base non valida: %d\n", ft_atoi_base("123", 20));  // 0 (base fuori range)
    
    return 0;
}
