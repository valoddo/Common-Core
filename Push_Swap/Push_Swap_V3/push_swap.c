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

// static void	test_argv2(char **c)
// {
// 	int	i;

// 	i = 0;

// 	printf("Test argv:\n");
// 	while (c[i])
// 	{
// 		printf("%s\n", c[i]);
// 		i++;
// 	}
// }
// static void test_fill_a (t_stack *a) 
// {
// 	    printf("Stack after filling:\n");
//         while (a) // Stampa lo stack per il controllo 
// 		{
// 			printf("%d\n", a->value);
// 			a = a->next;
// 		}
// }

static void test_index_a (t_stack *a) 
{
	    printf("Stack index:\n");
        while (a) // Stampa lo stack per il controllo 
		{
			printf("%d->", a->value);
			printf("%d\n", a->index);
			a = a->next;
		}
}

static void	push_swap_loop(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int	pos;

	pos = 0;
	while (*b)
	{
		ft_set_index(*a);
		ft_set_index(*b);
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

// static void	ft_push_swap(t_stack **a, t_stack **b)
// {
// 	int		len_a;
// 	int		median_value;
// 	t_stack	*tmp;

// 	median_value = 0;
// 	tmp = *a;
// 	while (tmp)
// 	{
// 		median_value += tmp->value;
// 		tmp = tmp->next;
// 	}
// 	len_a = ft_stacklen(*a);
// 	median_value = median_value / len_a;
// 	while (len_a -- > 3)
// 	{
// 		ft_push_b(a, b);
// 		if ((*b)->value > median_value)
// 			ft_reverse_b(b);
// 	}
// 	sort_three(a);
// 	push_swap_loop(a, b);
// }

static void	ft_push_swap(t_stack **a, t_stack **b)
{
	int		len_a;
	int		median;
	t_stack	*tmp;

	tmp = *a;
	ft_set_index(*a);
	len_a = ft_stacklen(*a);
	median = len_a / 2;
	while (len_a -- > 3)
	{
		if (tmp->index > median)
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

	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		ft_error(&a, "Error: insert items", argv, 1);
	else if (argc == 2)
		argv = ft_split(argv[0], argv[1], ' ');
	//test_argv2(argv);
	ft_fill_stack(&a, argv, argc);
	// printf("stack dopo sort\n");
	if (ft_stacklen(a) <= 5)
		ft_sort_small_stack(&a, &b);
	else
		ft_push_swap(&a, &b);
	test_index_a (a);
	ft_free_stack(&a);
	ft_free_stack(&b);
	if (argc == 2)
		ft_free_argv(argv);
	return (0);
}
