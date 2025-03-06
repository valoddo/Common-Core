/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenoni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:28:36 by lmenoni           #+#    #+#             */
/*   Updated: 2025/02/24 16:28:39 by lmenoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include "my_libft/libft.h"

typedef struct s_intlist
{
	int					content;
	struct s_intlist	*next;
	struct s_intlist	*prev;
	struct s_intlist	*target;
	unsigned int		idx;
	unsigned int		curr_pos;
	unsigned int		price;
	bool				upp_med;
}						t_intlist;

typedef struct s_stack
{
	t_intlist		*top;
	t_intlist		*bottom;
	unsigned int	size;
}					t_stack;

typedef struct s_data
{
	t_stack				*a;
	t_stack				*b;
	unsigned long int	moves;
	unsigned int		max_num;
}						t_data;

int			main(int ac, char *av[]);
void		init_struct(t_data *data, char **av);
void		populate_stack(char **av, t_stack *stack);
void		sa(t_data *data);
void		sb(t_data *data);
void		ss(t_data *data);
void		swap(t_stack *stack);
void		pa(t_data *data);
void		pb(t_data *data);
void		push(t_stack *stack, t_intlist *new);
t_intlist	*get_top(t_stack *stack);
void		rra(t_data *data);
void		rrb(t_data *data);
void		rrr(t_data *data);
void		rrotate(t_stack *stack);
void		ra(t_data *data);
void		rb(t_data *data);
void		rr(t_data *data);
void		rotate(t_stack *stack);
int			int_lstsize(t_intlist *lst);
t_intlist	*int_lstlast(t_intlist *lst);
void		int_lstadd_back(t_intlist **lst, t_intlist *new);
t_intlist	*int_lstnew(int content);
void		check_input(char **av);
int			check_overflow(char **av);
int			check_dup(char **av);
int			check_int(char **av);
int			check_minmax(char *s);
void		indexing(t_stack *stack, t_data *data);
void		sort_algo(t_data *data);
void		set_data(t_data *data);
void		move_data(t_data *data);
void		set_price(t_intlist *b, int b_size, int a_size);
void		set_target(t_intlist *a, t_intlist *b, t_data *data);
int			find_target(t_intlist *a, unsigned int b_idx,
				t_intlist **target, t_data *data);
void		set_curr_pos(t_stack *stack);
void		tiny_sort(t_data *data);
void		finish_rotate(t_stack *stack, t_intlist *obj, char c);
void		rrotate_both(t_data *data, t_intlist *cheapest);
void		rotate_both(t_data *data, t_intlist *cheapest);
t_intlist	*find_cheapest(t_intlist *b, int size);
t_intlist	*find_smallest(t_intlist *a, unsigned int size);
int			check_order(t_stack *a);

#endif