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

typedef struct s_stack
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	// bool				above_median;
	// bool				cheapest;
	struct s_stack		*target_node;
	struct s_stack		*next;
	struct s_stack		*prev;
}				t_stack;

char	**ft_split(char const *s0, char const *s1, char c);
int		ft_error(int i);
// void test(char **c);
#endif