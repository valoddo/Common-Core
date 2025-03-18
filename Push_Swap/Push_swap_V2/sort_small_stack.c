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

// Ordina 2 elementi
static void	sort_two(t_stack **a)
{
	if ((*a)->index > (*a)->next->index) // ex. 2, 1
	{
		ft_swap_a(a);
	}		
}

// Ordina 3 elementi
static void	sort_three(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->index;
	mid = (*a)->next->index;
	bot = (*a)->next->next->index;
	if (top > mid && mid < bot && bot > top) //ex. 3, 1, 5
		ft_swap_a(a);
	else if (top > mid && mid > bot) //ex. 5, 3, 1
	{
		ft_rotate_a(a);
		ft_swap_a(a);
	}
	else if (top > mid && mid < bot && bot < top) //ex. 5, 1, 3
		ft_rotate_a(a);
	else if (top < mid && mid > bot && bot > top) //ex. 1, 5, 3
	{
		ft_swap_a(a);
		ft_rotate_a(a);
	}
	else if (top < mid && mid > bot && bot < top) //ex. 3, 5, 1
		ft_reverse_a(a);
}

static void	sort_five(t_stack **a, t_stack **b)
{
	while (ft_stacklen(*a) > 3)
	{
		t_stack *current;
		int pos;
		
		current = *a;
		pos = 0;
		while (current && current->index >= 2) // Trova la posizione del primo elemento con indice >2
		{
			current = current->next;
			pos++;
		}
		if (pos <= ft_stacklen(*a) / 2) // Scegli la rotazione ottimale (ra o rra)
		{
			while (pos-- > 0)
				ft_rotate_a(a);
		}
		else
		{
			pos = ft_stacklen(*a) - pos;
			while (pos-- > 0)
				ft_reverse_a(a);
		}
		ft_push_b(a, b);
	}
}

// Ordina 4-5 elementi
void	ft_easy_sort(t_stack **a, t_stack **b)
{
	if (ft_stacklen(*a) == 2)
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
