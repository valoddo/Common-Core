/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:49:22 by vloddo            #+#    #+#             */
/*   Updated: 2025/05/20 13:31:56 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->program->num_philos == 1)
		return (ft_single_philo(philo));
	if (philo->id % 2 == 0)
		ft_usleep(philo->time_to_eat / 2, philo->program);
	while (1)
	{
		if (ft_check_meals(philo) || ft_check_death(philo))
			return (NULL);
		ft_take_forks(philo);
		ft_eat(philo);
		ft_release_forks(philo);
		if (ft_check_meals(philo))
			return (NULL);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}

void	*ft_single_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->write_lock);
	ft_printf("0 1 has taken a fork\n");
	pthread_mutex_unlock(philo->write_lock);
	pthread_mutex_lock(philo->dead_lock);
	*(philo->dead) = 1;
	pthread_mutex_unlock(philo->dead_lock);
	return (NULL);
}

int	ft_check_death(t_philo *philo)
{
	size_t	current;

	pthread_mutex_lock(philo->meal_lock);
	pthread_mutex_lock(philo->dead_lock);
	current = ft_get_current_time(philo->program);
	if (philo->time_to_die <= (current - philo->last_meal))
	{
		*(philo->dead) = 1;
		pthread_mutex_unlock(philo->dead_lock);
		pthread_mutex_unlock(philo->meal_lock);
		return (1);
	}
	else if (*(philo->dead) == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		pthread_mutex_unlock(philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	ft_check_meals(t_philo *philo)
{
	if (philo->num_times_to_eat == -1)
		return (0);
	pthread_mutex_lock(philo->meal_lock);
	if (philo->meals_eaten >= philo->num_times_to_eat)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

void	ft_log_action(t_philo *philo, char *action)
{
	size_t	timestamp;

	pthread_mutex_lock(philo->dead_lock);
	if (*(philo->dead) == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return ;
	}
	pthread_mutex_unlock(philo->dead_lock);
	timestamp = ft_get_current_time(philo->program) - philo->start_time;
	pthread_mutex_lock(philo->write_lock);
	ft_printf("%u %d %s\n", timestamp, philo->id, action);
	pthread_mutex_unlock(philo->write_lock);
}
