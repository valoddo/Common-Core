/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:21:10 by vloddo            #+#    #+#             */
/*   Updated: 2025/02/28 14:21:11 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int					value;
	int					index;
	int					current_position;
	int					push_price;
	bool				above_median;
	struct s_stack		*target_node;
	struct s_stack		*next;
}				t_stack;

// ft_split.c
char	**ft_split(char const *s0, char const *s1, char c);
int	word_count(char *s, char c);

// ft_fill_stack.c
void	ft_fill_stack(t_stack **a, char **argv, int argc);

// index_bubble.c
void	ft_set_index(t_stack *a);
int	ft_check_order(t_stack *a);

// push_swap_utils.c
int		ft_stacklen(t_stack *a);
void	ft_error(t_stack **a, char *msg, char **argv, int argc);
void	ft_putstr(char *str);
void	ft_free_stack(t_stack **stack);
void	ft_free_argv(char **argv);

// sort_small_stack.c
void	ft_sort_small_stack(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	ft_better_move(int pos, t_stack **a);

// algorithm.c
void	ft_target_node(t_stack *a, t_stack *b);
t_stack	*ft_min_node(t_stack *a);
void	ft_move_node(t_stack **a, t_stack **b);
t_stack	*ft_cheapest(t_stack *b);
void	finish_rotation(t_stack **stack, t_stack *node, char stack_name);

// swap_command.c
void	ft_swap_a(t_stack **a);
void	ft_swap_b(t_stack **b);
void	ft_swap_ab(t_stack **a, t_stack **b);

// rotate_command.c
void	ft_rotate_a(t_stack **a);
void	ft_rotate_b(t_stack **b);
void	ft_rotate_ab(t_stack **a, t_stack **b);

//reverse_command.c
void	ft_reverse_a(t_stack **a);
void	ft_reverse_b(t_stack **b);
void	ft_reverse_ab(t_stack **a, t_stack **b);

//push_command.c
void	ft_push_a(t_stack **a, t_stack **b);
void	ft_push_b(t_stack **a, t_stack **b);

// ft_calloc.c
void	*ft_calloc(size_t num, size_t size);

//push_swap.c
void	ft_current_position(t_stack *stack);
void	ft_set_price(t_stack *a, t_stack *b);

#endif
