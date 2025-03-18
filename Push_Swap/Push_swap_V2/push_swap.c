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

/*static void	test_argv2(char **c)
{
	int	i;

	i = 0;

	printf("Test argv:\n");
	while (c[i])
	{
		printf("%s\n", c[i]);
		i++;
	}
}*/
static void test_fill_a (t_stack *a) 
{
	    printf("Stack after filling:\n");
        while (a) // Stampa lo stack per il controllo 
		{
			printf("%d\n", a->value);
			a = a->next;
		}
}

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

// Trova il nodo target in A per un elemento di B
/*t_stack	*find_target_node(t_stack *a, int b_index)
{
	t_stack	*target = NULL;
	int		min_diff = INT_MAX;

	while (a)
	{
		if (a->final_index > b_index && a->final_index - b_index < min_diff)
		{
			min_diff = a->final_index - b_index;
			target = a;
		}
		a = a->next;
	}
	return (target ? target : find_min_node(a));
}

// Calcola il costo per spostare ogni nodo
void	calculate_push_cost(t_stack *a, t_stack *b)
{
	int	len_a = ft_stacklen(a);
	int	len_b = ft_stacklen(b);
	int	cost_a, cost_b;

	while (b)
	{
		cost_a = b->target_node->current_position;
		if (cost_a > len_a / 2)
			cost_a = len_a - cost_a;
		cost_b = b->current_position;
		if (cost_b > len_b / 2)
			cost_b = len_b - cost_b;
		b->push_price = cost_a + cost_b;
		b = b->next;
	}
}*/

/*static void	push_swap(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_stacklen(*a);
	if (len <= 1)
		return;
	while (len > 0) // Divide lo stack in chunk
	{
		if ((*a)->index < len / 2)
			ft_push_b(a, b);
		else
			ft_rotate_a(a);
	}
	while (*b) // Riordina e reintegra
	{
		find_target_node(*a, *b);
		execute_cheapest_move(a, b);
	}
	final_rotate(a); // Allinea lo stack A
}*/

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;

	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		ft_error(&a, "Error: insert items", 2, argv, 1);
	else if (argc == 2)
		argv = ft_split(argv[0], argv[1], ' ');

	//test_argv2(argv);

	ft_fill_stack(&a, argv, argc);

	test_fill_a (a);

	ft_set_index(a);
	if (ft_stacklen(a) <= 5)
		ft_easy_sort(&a, &b);

	printf("stack dopo sort\n");
	test_index_a (a);

	ft_free_stack(&a);
	ft_free_stack(&b);
	if (argc == 2)
		ft_free_argv(argv);
	return (0);
}



/*	test_fill_a (a);
	ft_swap_a(&a);
	printf("test swap a\n");
	test_fill_a (a);
	ft_rotate_a(&a);
	printf("test rotate a\n");
	test_fill_a (a);
	//ft_error(&a, "Test memory free", 1);
	//ft_fill_stack(&a, argv);*/
