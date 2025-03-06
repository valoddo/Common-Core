/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenoni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:55:18 by lmenoni           #+#    #+#             */
/*   Updated: 2025/03/04 18:55:20 by lmenoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_intlist	*find_smallest(t_intlist *a, unsigned int size)
{
	unsigned int	i;
	t_intlist		*smallest;

	i = 0;
	smallest = NULL;
	while (i < size)
	{
		if (smallest == NULL || a->idx < smallest->idx)
			smallest = a;
		a = a->next;
		i++;
	}
	return (smallest);
}

t_intlist	*find_cheapest(t_intlist *b, int size)
{
	int			i;
	t_intlist	*cheapest;

	i = 0;
	cheapest = NULL;
	while (i < size)
	{
		if (cheapest == NULL || b->price < cheapest->price)
			cheapest = b;
		b = b->next;
		i++;
	}
	return (cheapest);
}

void	rotate_both(t_data *data, t_intlist *cheapest)
{
	while (data->b->top != cheapest && data->a->top != cheapest->target)
		rr(data);
}

void	rrotate_both(t_data *data, t_intlist *cheapest)
{
	while (data->b->top != cheapest && data->a->top != cheapest->target)
		rrr(data);
}

void	finish_rotate(t_stack *stack, t_intlist *obj, char c)
{
	while (stack->top != obj)
	{
		if (obj->upp_med)
		{
			rotate(stack);
			ft_printf("r%c\n", c);
		}
		else
		{
			rrotate(stack);
			ft_printf("rr%c\n", c);
		}
	}
}
