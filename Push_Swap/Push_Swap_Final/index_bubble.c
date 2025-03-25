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

static void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	copy_stack_to_array(t_stack *a, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = a->value;
		a = a->next;
		i++;
	}
}

static void	assign_indexes(t_stack *a, int *arr, int size)
{
	int	i;

	while (a)
	{
		i = 0;
		while (i < size)
		{
			if (a->value == arr[i])
				a->index = i;
			i++;
		}
		a = a->next;
	}
}

void	ft_set_index(t_stack *a)
{
	int	size;
	int	*arr;

	size = ft_stacklen(a);
	arr = ft_calloc(size, sizeof(int));
	if (!arr)
		return ;
	copy_stack_to_array(a, arr, size);
	bubble_sort(arr, size);
	assign_indexes(a, arr, size);
	free(arr);
}
