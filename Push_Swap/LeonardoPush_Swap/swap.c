/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenoni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:40:29 by lmenoni           #+#    #+#             */
/*   Updated: 2025/02/26 17:40:32 by lmenoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int				t;
	unsigned int	i;

	t = 0;
	i = 0;
	t = stack->top->content;
	i = stack->top->idx;
	stack->top->content = stack->top->next->content;
	stack->top->idx = stack->top->next->idx;
	stack->top->next->content = t;
	stack->top->next->idx = i;
}

void	ss(t_data *data)
{
	swap(data->b);
	swap(data->a);
	ft_printf("ss\n");
	data->moves++;
}

void	sb(t_data *data)
{
	swap(data->b);
	ft_printf("sb\n");
	data->moves++;
}

void	sa(t_data *data)
{
	swap(data->a);
	ft_printf("sa\n");
	data->moves++;
}
