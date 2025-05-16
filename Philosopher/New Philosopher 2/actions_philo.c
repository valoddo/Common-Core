/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:49:22 by vloddo            #+#    #+#             */
/*   Updated: 2025/05/16 21:06:14 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

// 1. Controllo Morte:
// int	ft_check_death(t_philo *philo)
// {
// 	pthread_mutex_lock(philo->dead_lock);
// 	if (*(philo->dead) == 1)
// 	{
// 		pthread_mutex_unlock(philo->dead_lock);
// 		return (1);
// 	}
// 	pthread_mutex_unlock(philo->dead_lock);
// 	return (0);
// }

int	ft_check_death(t_philo *philo)
{
	size_t current_time;

	current_time = ft_get_current_time(philo->program);
	pthread_mutex_lock(philo->meal_lock);
	pthread_mutex_lock(philo->dead_lock);
	if (*(philo->dead) == 0 && (current_time - philo->last_meal) >= philo->time_to_die)
	{
		*(philo->dead) = 1;
		pthread_mutex_unlock(philo->dead_lock);
		pthread_mutex_unlock(philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	pthread_mutex_unlock(philo->meal_lock);
	return (*(philo->dead));
}


// 1. Controllo Meals:
int	ft_check_meals(t_philo *philo)
{
	if (philo->num_times_to_eat == -1)
		return (0); // Mangia infinitamente
	pthread_mutex_lock(philo->meal_lock);
	if (philo->meals_eaten >= philo->num_times_to_eat)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

void	ft_take_forks(t_philo *philo)
{
    // Strategia anti-deadlock: filosofi pari partono dopo e prendono prima la forchetta sinistra e poi la destra
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		ft_log_action(philo, "has taken left fork");
		pthread_mutex_lock(philo->r_fork);
		ft_log_action(philo, "has taken right fork");
	}
	else
	{
		pthread_mutex_lock(philo->r_fork); //filosofi dispari iniziano prima e prendono prima la forchetta destra e poi la sinistra
		ft_log_action(philo, "has taken right fork");
		pthread_mutex_lock(philo->l_fork);
		ft_log_action(philo, "has taken left fork");
	}
}

//2. Gestione Forchette:
void	ft_release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

//3. Azioni del Filosofo:
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
}
