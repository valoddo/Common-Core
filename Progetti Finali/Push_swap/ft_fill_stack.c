/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:33:31 by vloddo            #+#    #+#             */
/*   Updated: 2025/03/04 12:33:35 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atoi(char *argv, int *nb)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (argv[i] == '+' || argv[i] == '-')
	{
		if (argv[i] == '-')
			sign = -1;
		i++;
	}
	while (argv[i] != '\0')
	{
		if (argv[i] >= '0' && argv[i] <= '9')
			result = (result * 10) + (argv[i] - '0');
		if ((sign == 1 && result > INT_MAX) || \
			(sign == -1 && result > ((long long)INT_MAX + 1)) || \
			(argv[i] < '0' || argv[i] > '9'))
			return (0);
		i++;
	}
	*nb = (int)(result * sign);
	return (1);
}

static int	ft_nb_is_present(t_stack *a, int nb)
{
	while (a)
	{
		if (a->value == nb)
			return (1);
		a = a->next;
	}
	return (0);
}

static t_stack	*ft_new_node(int nb)
{
	t_stack	*new_node;

	new_node = ft_calloc(1, sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = nb;
	new_node->next = NULL;
	return (new_node);
}

static void	ft_insert_node(t_stack **a, t_stack *new_node)
{
	t_stack	*last;

	if (*a == NULL)
	{
		*a = new_node;
		new_node->next = NULL;
	}
	else
	{
		last = *a;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
	}
}

void	ft_fill_stack(t_stack **a, char **argv, int argc)
{
	int		j;
	int		nb;
	t_stack	*new_node;

	new_node = NULL;
	nb = 0;
	j = 1;
	while (argv[j])
	{
		if (ft_atoi(argv[j], &nb) == 0)
			ft_error(a, "Error: insert correct number", argv, argc);
		if (ft_nb_is_present(*a, nb) == 1)
			ft_error(a, "Error: number presents more than once", argv, argc);
		new_node = ft_new_node(nb);
		ft_insert_node(a, new_node);
		j++;
	}
}
