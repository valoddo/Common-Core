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

void	ft_current_position(t_stack *stack)
{
	int	i;
	int	centerline;

	i = 0;
	centerline = 0;
	if (stack == NULL)
		return ;
	centerline = ft_stacklen(stack) / 2;
	while (stack != NULL)
	{
		stack->current_position = i;
		if (i <= centerline)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	ft_set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stacklen(a);
	len_b = ft_stacklen(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->above_median))
			b->push_price = len_b - (b->current_position);
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += (len_a - b->target_node->current_position);
		b = b->next;
	}
}

static void	push_swap_loop(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		pos;

	pos = 0;
	while (*b)
	{
		ft_current_position(*a);
		ft_current_position(*b);
		ft_target_node(*a, *b);
		ft_set_price(*a, *b);
		ft_move_node(a, b);
	}
	ft_set_index(*a);
	pos = 0;
	tmp = *a;
	while (tmp && tmp->index != 0)
	{
		tmp = tmp->next;
		pos++;
	}
	if (tmp)
		ft_better_move(pos, a);
}

static void	ft_push_swap(t_stack **a, t_stack **b)
{
	int		len_a;
	int		median_value;
	t_stack	*tmp;

	median_value = 0;
	tmp = *a;
	while (tmp)
	{
		median_value += tmp->value;
		tmp = tmp->next;
	}
	len_a = ft_stacklen(*a);
	median_value = median_value / len_a;
	while (len_a-- > 3)
	{
		if ((*a)->value >= median_value)
		{
			ft_push_b(a, b);
			ft_rotate_b(b);
		}
		else
			ft_push_b(a, b);
	}
	sort_three(a);
	push_swap_loop(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0') || \
		(word_count(argv[1], ' ') == 0))
		return (0);
	else if (argc == 2)
		argv = ft_split(argv[0], argv[1], ' ');
	ft_fill_stack(&a, argv, argc);
	if (ft_stacklen(a) <= 5)
		ft_sort_small_stack(&a, &b);
	else
		ft_push_swap(&a, &b);
	ft_free_stack(&a);
	ft_free_stack(&b);
	if (argc == 2)
		ft_free_argv(argv);
	return (0);
}
