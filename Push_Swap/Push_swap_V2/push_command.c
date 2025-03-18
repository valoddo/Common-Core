/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:20:52 by vloddo            #+#    #+#             */
/*   Updated: 2025/02/28 14:20:54 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_push_a(t_stack **a, t_stack **b)
{
	t_stack *temp;

	if (!*b) // Check if b is empty
		return;
	temp = *b;// Save the top of b
	*b = (*b)->next;// Move b's head to the next element
	temp->next = *a;// Link the saved node to a's current head
	*a = temp;// Update a's head to the saved node
	write(1, "pa\n", 3);
}

void	ft_push_b(t_stack **a, t_stack **b)
{
	t_stack *temp;
	if (!*a) // Check if a is empty
		return;
	temp = *a;// Save the top of a
	*a = (*a)->next;// Move a's head to the next element
	temp->next = *b;// Link the saved node to b's current head
	*b = temp;// Update b's head to the saved node
	write(1, "pb\n", 3);
}