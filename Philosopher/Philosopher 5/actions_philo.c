/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:49:22 by vloddo            #+#    #+#             */
/*   Updated: 2025/05/19 19:21:34 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	ft_take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		ft_log_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		ft_log_action(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		ft_log_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->l_fork);
		ft_log_action(philo, "has taken a fork");
	}
}

void	ft_release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = ft_get_current_time(philo->program);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_log_action(philo, "is eating");
	ft_usleep(philo->time_to_eat, philo->program);
}

void	ft_sleep(t_philo *philo)
{
	ft_log_action(philo, "is sleeping");
	ft_usleep(philo->time_to_sleep, philo->program);
}

void	ft_think(t_philo *philo)
{
	ft_log_action(philo, "is thinking");
	ft_usleep(1, philo->program);
}
