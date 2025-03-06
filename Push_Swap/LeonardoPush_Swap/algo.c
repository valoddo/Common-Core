/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenoni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:49:22 by lmenoni           #+#    #+#             */
/*   Updated: 2025/03/04 18:49:24 by lmenoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_stack *a)
{
	int			i;
	t_intlist	*t;

	i = 0;
	t = a->top;
	while (i < (int)a->size)
	{
		if (i != (int)t->idx)
			return (0);
		t = t->next;
		i++;
	}
	return (1);
}

void	tiny_sort(t_data *data)
{
	t_intlist	*t;

	t = data->a->top;
	if (t->idx > t->next->idx && t->idx > t->prev->idx)
		ra(data);
	else if (t->next->idx > t->idx && t->next->idx > t->prev->idx)
		rra(data);
	t = data->a->top;
	if (t->idx > t->next->idx)
		sa(data);
}

void	move_data(t_data *data)
{
	t_intlist	*cheapest;

	cheapest = find_cheapest(data->b->top, (int)data->b->size);
	if (cheapest->upp_med && cheapest->target->upp_med)
		rotate_both(data, cheapest);
	if (!cheapest->upp_med && !cheapest->target->upp_med)
		rrotate_both(data, cheapest);
	finish_rotate(data->a, cheapest->target, 'a');
	finish_rotate(data->b, cheapest, 'b');
	pa(data);
}

void	set_data(t_data *data)
{
	set_curr_pos(data->a);
	set_curr_pos(data->b);
	set_target(data->a->top, data->b->top, data);
	set_price(data->b->top, (int)data->b->size, (int)data->a->size);
}

void	sort_algo(t_data *data)
{
	while (data->a->size > 3)
	{
		pb(data);
		if (data->b->top->idx < (data->max_num / 2))
			rb(data);
	}
	tiny_sort(data);
	while (data->b->size > 0)
	{
		set_data(data);
		move_data(data);
	}
	finish_rotate(data->a, find_smallest(data->a->top, data->a->size), 'a');
}
