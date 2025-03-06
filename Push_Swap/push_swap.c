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

/*void	test_argv2(char **c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	printf("Test argv:\n");
	while (c[i])
	{
		printf("%s\n", c[i]);
		i++;
	}
}*/
void test_fill_a (t_stack *a) 
{
	    printf("Stack after filling:\n");
        while (a) // Stampa lo stack per il controllo 
		{
			printf("%d\n", a->value);
			a = a->next;
		}
}


int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;

	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		ft_error(2);
	else if (argc == 2)
		argv = ft_split(argv[0], argv[1], ' ');
	//test_argv2(argv);
	ft_fill_stack(&a, argv);
	test_fill_a(a);
	return (0);
}
