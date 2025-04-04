/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:21:41 by vloddo            #+#    #+#             */
/*   Updated: 2025/02/28 15:21:44 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacklen(t_stack *a)
{
	int	i;

	i = 0;
	if (!a)
		return (0);
	while (a != NULL)
	{
		i++;
		a = a->next;
	}
	return (i);
}

void	ft_error(t_stack **a, char *msg, char **argv, int argc)
{
	ft_putstr(msg);
	if (a)
		ft_free_stack(a);
	if (argc == 2)
		ft_free_argv(argv);
	exit(1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\n", 1);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*stack = NULL;
}

void	ft_free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}
