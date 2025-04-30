/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:49:22 by vloddo            #+#    #+#             */
/*   Updated: 2025/04/30 21:10:15 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void *philo_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    if (philo->id % 2 == 0) // Solo i filosofi con ID dispari iniziano prendendo la forchetta destra
        ft_usleep(philo->time_to_eat / 2);

    while (1)
    {
        if (check_death(philo) || check_meals(philo)) // 1. Controllo morte
            break;
        take_forks(philo); // 2. Prendi le forchette
        eat(philo); // 3. Mangia
        release_forks(philo); // 4. Rilascia forchette
        philo_sleep(philo); // 5. Dormi
        think(philo); // 6. Pensiero
    }
    return (NULL);
}

// 1. Controllo Morte/Meals:
int check_death(t_philo *philo)
{
    pthread_mutex_lock(philo->dead_lock);
    if (*philo->dead == 1)
    {
        pthread_mutex_unlock(philo->dead_lock);
        return (1);
    }
    pthread_mutex_unlock(philo->dead_lock);
    return (0);
}

int check_meals(t_philo *philo)
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

void take_forks(t_philo *philo)
{
    // Strategia anti-deadlock: filosofi dispari prendono prima la destra
    if (philo->id % 2 == 0)
    {
        pthread_mutex_lock(philo->l_fork);
        log_action(philo, "has taken a fork");
        pthread_mutex_lock(philo->r_fork);
        log_action(philo, "has taken a fork");
    }
    else
    {
        pthread_mutex_lock(philo->r_fork);
        log_action(philo, "has taken a fork");
        pthread_mutex_lock(philo->l_fork);
        log_action(philo, "has taken a fork");
    }
}

//2. Gestione Forchette:
void release_forks(t_philo *philo)
{
    pthread_mutex_unlock(philo->l_fork);
    pthread_mutex_unlock(philo->r_fork);
}

//3. Azioni del Filosofo:
void eat(t_philo *philo)
{
    pthread_mutex_lock(philo->meal_lock);
    philo->last_meal = get_current_time();
    philo->meals_eaten++;
    pthread_mutex_unlock(philo->meal_lock);
    
    log_action(philo, "is eating");
    ft_usleep(philo->time_to_eat);
}

void philo_sleep(t_philo *philo)
{
    log_action(philo, "is sleeping");
    ft_usleep(philo->time_to_sleep);
}

void think(t_philo *philo)
{
    log_action(philo, "is thinking");
}

//4. Logging Sincronizzato:
void log_action(t_philo *philo, char *action)
{
    size_t timestamp;

    pthread_mutex_lock(philo->dead_lock);
    if (*philo->dead == 1)
    {
        pthread_mutex_unlock(philo->dead_lock);
        return;
    }
    pthread_mutex_unlock(philo->dead_lock);
    timestamp = get_current_time() - philo->start_time;
    pthread_mutex_lock(philo->write_lock);
    ft_printf("%zu %d %s\n", timestamp, philo->id, action);
    pthread_mutex_unlock(philo->write_lock);
}