/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenoni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:51:12 by lmenoni           #+#    #+#             */
/*   Updated: 2025/03/04 18:51:14 by lmenoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_curr_pos(t_stack *stack)
{
	unsigned int	i;
	t_intlist		*t;

	i = 0;
	t = stack->top;
	while (i < stack->size)
	{
		t->curr_pos = i;
		if (i < (stack->size / 2))
			t->upp_med = true;
		else
			t->upp_med = false;
		t = t->next;
		i++;
	}
}

int	find_target(t_intlist *a, unsigned int b_idx,
			t_intlist **target, t_data *data)
{
	unsigned int	j;
	int				best;

	j = 0;
	best = -1;
	while (j < data->a->size)
	{
		if (a->idx > b_idx && ((int)a->idx < best || best == -1))
		{
			best = a->idx;
			*target = a;
		}
		a = a->next;
		j++;
	}
	return (best);
}

void	set_target(t_intlist *a, t_intlist *b, t_data *data)
{
	unsigned int	i;
	int				best;
	t_intlist		*target;

	i = 0;
	best = -1;
	while (i < data->b->size)
	{
		best = find_target(a, b->idx, &target, data);
		if (best == -1)
			b->target = find_smallest(a, data->a->size);
		else
			b->target = target;
		b = b->next;
		i++;
	}
}

void	set_price(t_intlist *b, int b_size, int a_size)
{
	int	i;

	i = 0;
	while (i < b_size)
	{
		if (b->upp_med)
			b->price = b->curr_pos;
		else
			b->price = b_size - b->curr_pos;
		if (b->target->upp_med)
			b->price += b->target->curr_pos;
		else
			b->price += a_size - b->target->curr_pos;
		b = b->next;
		i++;
	}
}
