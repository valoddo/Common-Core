/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:49:22 by vloddo            #+#    #+#             */
/*   Updated: 2025/05/15 18:29:42 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	*ft_philo_routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	if (philo->id % 2 == 0) // Solo i filosofi con ID dispari iniziano prendendo la forchetta destra
		ft_usleep(philo->time_to_eat / 2, philo->program);

	while (1)
	{
		if (ft_check_death(philo)) // 1. Controllo morte
			return (NULL);
		if (ft_check_meals(philo)) // 1. Controllo meals
			return (NULL);
		ft_take_forks(philo); // 2. Prendi le forchette
		ft_eat(philo); // 3. Mangia
		ft_release_forks(philo); // 4. Rilascia forchette
		if (ft_check_meals(philo)) // 1. Controllo meals
			return (NULL);
		ft_sleep(philo); // 5. Dormi
		ft_think(philo); // 6. Pensiero
	}
	return (NULL);
}

// 1. Controllo Morte:
int	ft_check_death(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*(philo->dead) == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
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
    // Strategia anti-deadlock: filosofi pari prendono prima la sinistra e i filosofi dispari prendono prima la destra
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

//4. Logging Sincronizzato:
void	ft_log_action(t_philo *philo, char *action)
{
	size_t timestamp;

	pthread_mutex_lock(philo->dead_lock);
	if (*(philo->dead) == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return;
	}
	pthread_mutex_unlock(philo->dead_lock);
	timestamp = ft_get_current_time(philo->program) - philo->start_time;
	pthread_mutex_lock(philo->write_lock);
	ft_printf("%u %d %s\n", timestamp, philo->id, action);
	pthread_mutex_unlock(philo->write_lock);
}

void *ft_monitor(void *arg)
{
    t_program *program = (t_program *)arg;
    int all_ate;
    size_t current_time;
    int i;

    while (1)
    {
        all_ate = 1;
        i = 0;
        while (i < program->num_philos)
        {
            pthread_mutex_lock(&program->meal_lock);
            current_time = ft_get_current_time(program);
            if (current_time - program->philos[i].last_meal > program->philos[i].time_to_die)
            {
                pthread_mutex_lock(&program->dead_lock);
                program->dead_flag = 1;
                pthread_mutex_unlock(&program->dead_lock);
                ft_log_action(&program->philos[i], "died");
                pthread_mutex_unlock(&program->meal_lock);
                return (NULL);
            }
            if (program->philos[i].num_times_to_eat != -1 && 
                program->philos[i].meals_eaten < program->philos[i].num_times_to_eat)
                all_ate = 0;
            pthread_mutex_unlock(&program->meal_lock);
            i++;
        }
        if (all_ate)
        {
            pthread_mutex_lock(&program->dead_lock);
            program->dead_flag = 1;
            pthread_mutex_unlock(&program->dead_lock);
            return (NULL);
        }
        ft_usleep(1, program);
    }
    return (NULL);
}
