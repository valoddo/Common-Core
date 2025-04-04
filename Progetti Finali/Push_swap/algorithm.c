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

void	ft_target_node(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	int		best_match;

	while (b)
	{
		best_match = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match)
			{
				best_match = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == INT_MAX)
			b->target_node = ft_min_node(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

t_stack	*ft_min_node(t_stack *a)
{
	t_stack	*min_node;
	int		min;

	if (a == NULL)
		return (NULL);
	min = INT_MAX;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			min_node = a;
		}
		a = a->next;
	}
	return (min_node);
}

void	ft_move_node(t_stack **a, t_stack **b)
{
	t_stack		*cheapest_node;
	int			median_value;
	int			len_a;

	median_value = 0;
	len_a = ft_stacklen(*a);
	median_value = median_value / len_a;
	cheapest_node = ft_cheapest(*b);
	if (!cheapest_node)
		return ;
	if (cheapest_node->value >= median_value && \
		cheapest_node->target_node->value <= median_value)
		ft_rotate_ab(a, b);
	else if (!(cheapest_node->value >= median_value) && \
		!(cheapest_node->target_node->value <= median_value))
		ft_reverse_ab(a, b);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	ft_push_a(a, b);
}

t_stack	*ft_cheapest(t_stack *b)
{
	t_stack	*cheapest;
	int		min_price;

	cheapest = NULL;
	min_price = INT_MAX;
	if (!b)
		return (NULL);
	while (b)
	{
		if (b->push_price < min_price)
		{
			min_price = b->push_price;
			cheapest = b;
		}
		b = b->next;
	}
	return (cheapest);
}

void	finish_rotation(t_stack **stack, t_stack *node, char stack_name)
{
	while (*stack != node)
	{
		if (stack_name == 'a')
		{
			if (node->above_median)
				ft_rotate_a(stack);
			else
				ft_reverse_a(stack);
		}
		else if (stack_name == 'b')
		{
			if (node->above_median)
				ft_rotate_b(stack);
			else
				ft_reverse_b(stack);
		}
	}
}
