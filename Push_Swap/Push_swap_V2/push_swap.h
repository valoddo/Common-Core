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
#include <limits.h>

typedef struct s_stack
{
	int					value;
	int					index;
	int					current_position;
	int					push_price;
	// bool				above_median;
	// bool				cheapest;
	struct s_stack		*target_node;
	struct s_stack		*next;
	struct s_stack		*prev;
}				t_stack;

char	**ft_split(char const *s0, char const *s1, char c);

int		ft_stacklen(t_stack *a);
void	ft_error(t_stack **a, char *msg, int i, char ** argv, int argc);
void	ft_putstr(char *str);
void	ft_putstr(char *str);
void	ft_free_stack(t_stack **stack);
void	ft_free_argv(char **argv);

void	ft_fill_stack(t_stack **a, char **argv, int argc);

void	ft_swap_a(t_stack **a);
void	ft_swap_b(t_stack **b);
void	ft_swap_ab(t_stack **a, t_stack **b);

void	ft_rotate_a(t_stack **a);
void	ft_rotate_b(t_stack **b);
void	ft_rotate_ab(t_stack **a, t_stack **b);

void	ft_reverse_a(t_stack **a);
void	ft_reverse_b(t_stack **b);
void	ft_reverse_ab(t_stack **a, t_stack **b);

void	ft_push_a(t_stack **a, t_stack **b);
void	ft_push_b(t_stack **a, t_stack **b);

void	ft_easy_sort(t_stack **a, t_stack **b);
void	ft_set_index(t_stack *a);

#endif