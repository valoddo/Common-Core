/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenoni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:27:24 by lmenoni           #+#    #+#             */
/*   Updated: 2025/02/24 16:27:33 by lmenoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_stack *stack, t_data *data)
{
	unsigned int	i;
	t_intlist		*t;
	t_intlist		*curr;

	i = 0;
	curr = stack->top;
	while (i < stack->size)
	{
		t = curr->next;
		while (curr->content != t->content)
		{
			if (curr->content > t->content)
				curr->idx++;
			t = t->next;
		}
		if (curr->idx == (stack->size - 1))
			data->max_num = curr->idx;
		curr = curr->next;
		i++;
	}
}

void	empty_stacks(t_data *data)
{
	t_intlist		*t;
	unsigned int	i;

	i = 0;
	data->a->bottom->next = NULL;
	while (i < data->a->size)
	{
		t = data->a->top;
		data->a->top = data->a->top->next;
		free(t);
		i++;
	}
	free(data->a);
	free(data->b);
}

void	populate_stack(char **av, t_stack *stack)
{
	int	i;
	int	n;

	i = 1;
	while (av[i] != NULL)
	{
		n = ft_atoi(av[i]);
		if (stack->top == NULL)
		{
			stack->top = int_lstnew(n);
			stack->bottom = stack->top;
		}
		else
		{
			stack->bottom = int_lstnew(n);
			int_lstadd_back(&stack->top, stack->bottom);
		}
		i++;
	}
}

void	init_struct(t_data *data, char **av)
{
	data->a = (t_stack *)malloc(sizeof(t_stack) * 1);
	data->b = (t_stack *)malloc(sizeof(t_stack) * 1);
	data->max_num = 0;
	data->a->top = NULL;
	data->a->bottom = NULL;
	data->a->size = 0;
	data->b->top = NULL;
	data->b->bottom = NULL;
	data->b->size = 0;
	populate_stack(av, data->a);
	data->a->size = int_lstsize(data->a->top);
	data->max_num = data->a->size;
	data->a->top->prev = data->a->bottom;
	data->a->bottom->next = data->a->top;
	indexing(data->a, data);
	data->moves = 0;
}

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac < 2)
		return (ft_printf("ERROR\n Invalid arguments N^\n"));
	check_input(av);
	init_struct(&data, av);
	if (!check_order(data.a))
		sort_algo(&data);
	if (!check_order(data.a))
		ft_printf("ERROR\nAlgo failed\n");
	empty_stacks(&data);
	return (0);
}
