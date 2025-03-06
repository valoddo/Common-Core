/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenoni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:41:00 by lmenoni           #+#    #+#             */
/*   Updated: 2025/02/26 17:41:03 by lmenoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_stack *stack)
{
	stack->top = stack->bottom;
	stack->bottom = stack->bottom->prev;
}

void	rrr(t_data *data)
{
	rrotate(data->b);
	rrotate(data->a);
	ft_printf("rrr\n");
	data->moves++;
}

void	rrb(t_data *data)
{
	rrotate(data->b);
	ft_printf("rrb\n");
	data->moves++;
}

void	rra(t_data *data)
{
	rrotate(data->a);
	ft_printf("rra\n");
	data->moves++;
}
