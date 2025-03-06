/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenoni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:31:49 by lmenoni           #+#    #+#             */
/*   Updated: 2025/02/28 14:31:50 by lmenoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_minmax(char *s)
{
	int		sign;
	int		r;
	size_t	i;

	sign = 1;
	r = 0;
	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -sign;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		if ((sign == 1 && r > (INT_MAX - (s[i] - '0')) / 10)
			|| (sign < 0 && - r < (INT_MIN + (s[i] - '0')) / 10))
			return (1);
		r = (r * 10) + (s[i] - '0');
		i++;
	}
	return (0);
}

int	check_int(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i] != NULL)
	{
		j = 0;
		if (av[i][j] == '\0')
			return (1);
		while (av[i][j] == ' ' || (av[i][j] < 13 && av[i][j] > 9))
			j++;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (av[i][j] != '\0')
		{
			if (av[i][j] == '\0' || (av[i][j] < '0' || av[i][j] > '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_dup(char **av)
{
	int	t;
	int	i;
	int	j;

	i = 1;
	j = 0;
	t = 0;
	while (av[i] != NULL)
	{
		t = ft_atoi(av[i]);
		j = i + 1;
		while (av[j] != NULL)
		{
			if (t == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_overflow(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] == ' ' || (av[i][j] >= 9 && av[i][j] <= 13))
			j++;
		if (check_minmax(&av[i][j]) == 1)
			return (1);
		i++;
	}
	return (0);
}

void	check_input(char **av)
{
	if (check_int(av) == 1)
	{
		ft_printf("ERROR\nNon integer was found\n");
		exit (1);
	}
	if (check_overflow(av) == 1)
	{
		ft_printf("ERROR\nInteger exceeding integers limits was found\n");
		exit (1);
	}
	if (check_dup(av) == 1)
	{
		ft_printf("ERROR\nInteger duplicates were found in input\n");
		exit (1);
	}
}
