/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free_time_philo.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:49:22 by vloddo            #+#    #+#             */
/*   Updated: 2025/05/19 18:48:53 by vloddo           ###   ########.fr       */
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

size_t	ft_get_current_time(t_program *program)
{
	struct timeval	tv;
	
	if ( gettimeofday(&tv, NULL) == -1)
		ft_error_check("Error: gettimeofday failed", program, 2);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ft_usleep(size_t milliseconds, t_program *program)
{
	size_t	start;

	start = ft_get_current_time(program);
	while ((ft_get_current_time(program) - start) < milliseconds)
		usleep(500);
	return (0);
}
