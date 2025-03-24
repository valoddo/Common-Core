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

void	ft_set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;
	int	median_a;
	int	median_b;

	len_a = ft_stacklen(a);
	len_b = ft_stacklen(b);
	median_a = (len_a / 2);
	median_b = (len_b / 2);
	while (b)
	{
		if (b->index <= median_b)
			b->push_price = b->index;
		else
			b->push_price = len_b - b->index;
		if (b->target_node->index <= median_a)
			b->push_price += b->target_node->index;
		else
			b->push_price += (len_a - b->target_node->index);
		b = b->next;
	}
}

void	ft_move_node(t_stack **a, t_stack **b)
{
	t_stack			*cheapest_node;
	int				median_a;
	int				median_b;

	median_a = ft_stacklen(*a) / 2;
	median_b = ft_stacklen(*b) / 2;
	cheapest_node = ft_cheapest(*b);
	if (!cheapest_node)
		return ;
	while (*b != cheapest_node)
	{
		if (cheapest_node->index <= median_b)
			ft_rotate_b(b);
		else
			ft_reverse_b(b);
	}
	while (*a != cheapest_node->target_node)
	{
		if (cheapest_node->target_node->index <= median_a)
			ft_rotate_a(a);
		else
			ft_reverse_a(a);
	}
	ft_push_a(a, b);
}

/*void	ft_move_node(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;
	int		a_direction;
	int		b_direction;
	int		a_moves;
	int		b_moves;

	cheapest_node = ft_cheapest(*b);
	a_direction = 1;
	if (cheapest_node->target_node->index > ft_stacklen(*a) / 2)
		a_direction = 0;
	b_direction = 1;
	if (cheapest_node->index > ft_stacklen(*b) / 2)
		b_direction = 0;
	a_moves = cheapest_node->target_node->index;
	if (a_direction == 0)
		a_moves = ft_stacklen(*a) - cheapest_node->target_node->index;
	b_moves = cheapest_node->index;
	if (b_direction == 0)
		b_moves = ft_stacklen(*b) - cheapest_node->index;
	while (a_moves > 0 || b_moves > 0)
	{
		if (a_direction == b_direction && a_moves > 0 && b_moves > 0)
		{
			if (a_direction == 1)
				ft_rotate_ab(a, b);
			else
				ft_reverse_ab(a, b);
			a_moves--;
			b_moves--;
		}
		else if (a_moves > 0)
		{
			if (a_direction == 1)
				ft_rotate_a(a);
			else
				ft_reverse_a(a);
			a_moves--;
		}
		else if (b_moves > 0)
		{
			if (b_direction == 1)
				ft_rotate_b(b);
			else
				ft_reverse_b(b);
			b_moves--;
		}
  	ft_push_a(a, b);
	}
}*/

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
