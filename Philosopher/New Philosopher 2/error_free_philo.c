/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:49:22 by vloddo            #+#    #+#             */
/*   Updated: 2025/05/15 17:12:16 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	ft_error_check(char *msg, t_program *program, int exit_code)
{
	ft_printf("%s\n", msg);
	if (program != NULL)
		ft_clean_program(program);
	exit(exit_code);
}

// funzione per distruggere i mutex
void	ft_clean_program(t_program *program)
{
	int	i;

	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->write_lock);
	i = 0;
	while (i < program->num_philos)
	{
		pthread_mutex_destroy(&program->forks[i]);
		i++;
	}
}
