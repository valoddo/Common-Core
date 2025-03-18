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

static void	swap(t_stack **head)
{
	t_stack *first;
	t_stack *second;

	if (*head == NULL || (*head)->next == NULL)
		return; // Meno di due elementi
	first = *head;
	second = first->next;
	first->next = second->next;  // Aggiorna i puntatori
	second->next = first;
	*head = second;
}

void	ft_swap_a(t_stack **a)
{

	swap(a);
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ft_swap_ab(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
