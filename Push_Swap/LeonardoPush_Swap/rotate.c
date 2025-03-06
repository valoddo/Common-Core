/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenoni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:40:51 by lmenoni           #+#    #+#             */
/*   Updated: 2025/02/26 17:40:53 by lmenoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	stack->bottom = stack->top;
	stack->top = stack->top->next;
}

void	rr(t_data *data)
{
	rotate(data->b);
	rotate(data->a);
	ft_printf("rr\n");
	data->moves++;
}

void	rb(t_data *data)
{
	rotate(data->b);
	ft_printf("rb\n");
	data->moves++;
}

void	ra(t_data *data)
{
	rotate(data->a);
	ft_printf("ra\n");
	data->moves++;
}
