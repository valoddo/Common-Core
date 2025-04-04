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

static void	reverse(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*second_last;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	last = *head;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = first;
	*head = last;
}

void	ft_reverse_a(t_stack **a)
{
	reverse(a);
	write(1, "rra\n", 4);
}

void	ft_reverse_b(t_stack **b)
{
	reverse(b);
	write(1, "rrb\n", 4);
}

void	ft_reverse_ab(t_stack **a, t_stack **b)
{
	reverse(a);
	reverse(b);
	write(1, "rrr\n", 4);
}
