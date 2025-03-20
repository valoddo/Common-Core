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

// Prototipi delle funzioni aggiuntive
void		push_chunks(t_stack **a, t_stack **b, int chunk_start, int chunk_end);
void		sort_chunk(t_stack **a, t_stack **b, int chunk_size);
void		greedy_reinsert(t_stack **a, t_stack **b);
void		final_align(t_stack **a);

// Funzione principale modificata
void	push_swap(t_stack **a, t_stack **b)
{
	int	chunk;
	int	chunk_size;

	chunk_size = 20;
	if (ft_stacklen(*a) <= 5)
	{
		sort_small(a, b);
		return ;
	}
	chunk = 4; // Fase 1: Push dei chunk in ordine inverso (80-99, 60-79, ..., 0-19)
	while (chunk >= 0)
	{
		push_chunks(a, b, chunk * chunk_size, (chunk * chunk_size) + (chunk_size - 1));
		chunk--;
	}
	chunk = 0; // Fase 2: Ordina e reinserisci i chunk
	while (chunk < 5)
	{
		sort_chunk(a, b, chunk_size);
		greedy_reinsert(a, b);
		chunk++;
	}
	final_align(a); // Fase 3: Allineamento finale
}

// Implementazione nuove funzioni
void	push_chunks(t_stack **a, t_stack **b, int chunk_start, int chunk_end)
{
	int		i;
	int		count;
	int		stack_len;

	i = 0;
	count = 0;
	stack_len = ft_stacklen(*a);
	while (i < stack_len && count < 20)
	{
		if ((*a)->index >= chunk_start && (*a)->index <= chunk_end)
		{
			ft_push_b(a, b);
			if ((*b)->index > chunk_start + (chunk_end - chunk_start) / 2)
				ft_rotate_b(b);
			count++;
		}
		else
			ft_rotate_a(a);
		i++;
	}
}

void	sort_chunk(t_stack **a, t_stack **b, int chunk_size)
{
	int	bit;
	int	i;

	bit = 0;
	while (bit < 5)
	{
		i = 0;
		while (i < chunk_size)
		{
			if (((*b)->index >> bit) & 1)
				ft_rotate_b(b);
			else
				ft_push_a(a, b);
			i++;
		}
		while (ft_stacklen(*a) > 100 - chunk_size)
			ft_push_b(a, b);
		bit++;
	}
}

void	greedy_reinsert(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;
	int		cost_a;
	int		cost_b;

	while (*b)
	{
		init_nodes(*a, *b);
		cheapest = find_cheapest(*b);
		cost_a = cheapest->target->current_position;
		cost_b = cheapest->current_position;
		while (cost_a > 0 && cost_b > 0 && 
				cheapest->target->above_median && cheapest->above_median) // Esegui rotazioni ottimizzate
		{
			ft_rotate_r(a, b);
			cost_a--;
			cost_b--;
		}
		while (cost_a < 0 && cost_b < 0 && 
				!cheapest->target->above_median && !cheapest->above_median)
		{
			ft_reverse_rotate_r(a, b);
			cost_a++;
			cost_b++;
		}
		rotate_a_to_position(a, cost_a);
		rotate_b_to_position(b, cost_b);
		ft_push_a(a, b);
	}
}

void	final_align(t_stack **a)
{
	t_stack	*min_node;
	int		min_pos;
	int		stack_len;

	min_node = find_min_node(*a);
	min_pos = min_node->current_position;
	stack_len = ft_stacklen(*a);
	
	if (min_pos > stack_len / 2)
	{
		min_pos = stack_len - min_pos;
		while (min_pos--)
			ft_reverse_rotate_a(a);
	}
	else
	{
		while (min_pos--)
			ft_rotate_a(a);
	}
}

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

