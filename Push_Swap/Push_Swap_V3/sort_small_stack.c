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

static void	sort_two(t_stack **a)
{
	if ((*a)->index > (*a)->next->index)
	{
		ft_swap_a(a);
	}
}

void	sort_three(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->index;
	mid = (*a)->next->index;
	bot = (*a)->next->next->index;
	if (top > mid && mid < bot && bot > top)
		ft_swap_a(a);
	else if (top > mid && mid > bot)
	{
		ft_rotate_a(a);
		ft_swap_a(a);
	}
	else if (top > mid && mid < bot && bot < top)
		ft_rotate_a(a);
	else if (top < mid && mid > bot && bot > top)
	{
		ft_swap_a(a);
		ft_rotate_a(a);
	}
	else if (top < mid && mid > bot && bot < top)
		ft_reverse_a(a);
}

void	ft_better_move(int pos, t_stack **a)
{
	if (pos <= ft_stacklen(*a) / 2)
	{
		while (pos-- > 0)
		{
			ft_rotate_a(a);
		}
	}
	else
	{
		pos = ft_stacklen(*a) - pos;
		while (pos-- > 0)
			ft_reverse_a(a);
	}
}

static void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		pos;

	while (ft_stacklen(*a) > 3)
	{
		tmp = *a;
		pos = 0;
		while (tmp && tmp->index != 0)
		{
			tmp = tmp->next;
			pos++;
		}
		if (!tmp)
		{
			tmp = *a;
			pos = 0;
			while (tmp && tmp->index != 1)
			{
				tmp = tmp->next;
				pos++;
			}
		}
		ft_better_move(pos, a);
		ft_push_b(a, b);
	}
}

void	ft_sort_small_stack(t_stack **a, t_stack **b)
{
	ft_set_index(*a);
	if (ft_stacklen(*a) == 1)
		return ;
	else if (ft_stacklen(*a) == 2)
		sort_two(a);
	else if (ft_stacklen(*a) == 3)
		sort_three(a);
	else if (ft_stacklen(*a) <= 5)
	{
		sort_five(a, b);
		sort_three(a);
		while (*b)
			ft_push_a(a, b);
	}
}
