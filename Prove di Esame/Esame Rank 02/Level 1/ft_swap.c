/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:15:32 by vloddo            #+#    #+#             */
/*   Updated: 2025/02/04 12:17:43 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_swap(int *a, int*b)
{
	int c;
	
	c = *a;
	*a = *b;
	*b = c; 
}

#include <stdio.h>
int main()
{
        int a;
        int b;
        int *x;
        int *y;
        
        a = 1;
        b = 2;
        x = &a;
        y = &b;
        ft_swap(x, y);
        printf("%d %d", a, b);
        return (0);
}
