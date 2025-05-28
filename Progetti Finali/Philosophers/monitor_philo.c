/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:49:22 by vloddo            #+#    #+#             */
/*   Updated: 2025/05/22 18:32:13 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_monitor(void *arg)
{
	t_program	*program;
	int			i;

	program = (t_program *)arg;
	while (1)
	{
		i = 0;
		while (i < program->num_philos)
		{
			if (ft_check_death(&program->philos[i]))
			{
				ft_log_action_dead(&program->philos[i], "died");
				return (NULL);
			}
			i++;
		}
		if (ft_check_meals_completion(program))
			return (NULL);
	}
	return (NULL);
}

int	ft_check_meals_completion(t_program *program)
{
	int	i;
	int	done;

	done = 0;
	i = 0;
	while (i < program->num_philos)
	{
		pthread_mutex_lock(program->philos[i].meal_lock);
		if (program->philos[i].num_times_to_eat != -1 && \
			program->philos[i].meals_eaten >= \
			program->philos[i].num_times_to_eat)
			done++;
		pthread_mutex_unlock(program->philos[i].meal_lock);
		i++;
	}
	if (done == program->num_philos && program->num_philos > 1)
	{
		pthread_mutex_lock(program->philos[0].write_lock);
		printf("Each philosopher has aten %d times\n", \
				program->philos[0].num_times_to_eat);
		pthread_mutex_unlock(program->philos[0].write_lock);
		return (1);
	}
	return (0);
}

void	ft_log_action_dead(t_philo *philo, char *action)
{
	size_t	timestamp;

	pthread_mutex_lock(philo->dead_lock);
	if (*(philo->dead) == 1)
		philo->program->dead_flag = 1;
	pthread_mutex_unlock(philo->dead_lock);
	timestamp = ft_get_current_time(philo->program) - philo->start_time;
	pthread_mutex_lock(philo->write_lock);
	printf("%zu %d %s\n", timestamp, philo->id, action);
	pthread_mutex_unlock(philo->write_lock);
}
