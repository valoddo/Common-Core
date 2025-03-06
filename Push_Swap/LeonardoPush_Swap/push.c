/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenoni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:40:39 by lmenoni           #+#    #+#             */
/*   Updated: 2025/02/26 17:40:41 by lmenoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_intlist	*get_top(t_stack *stack)
{
	t_intlist	*t;

	t = stack->top;
	stack->bottom->next = stack->top->next;
	stack->top->next->prev = stack->bottom;
	stack->top = stack->top->next;
	t->next = NULL;
	t->prev = NULL;
	stack->size--;
	if (stack->size == 0)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	return (t);
}

void	push(t_stack *stack, t_intlist *new)
{
	if (stack->top == NULL)
	{
		stack->top = new;
		stack->bottom = new;
		new->next = new;
		new->prev = new;
	}
	else
	{
		stack->bottom->next = new;
		stack->top->prev = new;
		new->next = stack->top;
		new->prev = stack->bottom;
		stack->top = new;
	}
	stack->size++;
}

void	pb(t_data *data)
{
	t_intlist	*t;

	t = get_top(data->a);
	push(data->b, t);
	ft_printf("pb\n");
	data->moves++;
}

void	pa(t_data *data)
{
	t_intlist	*t;

	t = get_top(data->b);
	push(data->a, t);
	ft_printf("pa\n");
	data->moves++;
}
