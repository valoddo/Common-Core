/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:21:41 by vloddo            #+#    #+#             */
/*   Updated: 2025/02/28 15:21:44 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(int i)
{
	if (i == 2) //errore del main se non ci sono argomenti 
		write(1, "Error: insert items\n", 20);
	else if (i == 3) //errore nell'atoi se ci sono caratteri e non numeri
		write(1, "Error: insert correct number\n", 29);
	else if (i == 4) //errore nell'atoi se ci sono caratteri e non numeri
		write(1, "Error: number presents more than once\n", 38);
	return (0);
}


   