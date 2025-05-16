/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor_routine.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:49:22 by vloddo            #+#    #+#             */
/*   Updated: 2025/05/16 21:08:01 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	*ft_philo_routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	if (philo->program->num_philos == 1)
		return(ft_single_philo(philo));
	if (philo->id % 2 == 0) // Solo i filosofi con ID dispari iniziano prendendo la forchetta destra
		ft_usleep(philo->time_to_eat / 2, philo->program); // i filosofi pari Vengono ritardati di time_to_eat / 2 millisecondi prima di iniziare
	while (1)
	{
		// if (ft_check_death(philo) || ft_check_meals(philo)) // 1. Controllo morte o meals
		// 	return (NULL);
		pthread_mutex_lock(philo->dead_lock);
		if (*(philo->dead) == 1)
		{
			pthread_mutex_unlock(philo->dead_lock);
			return (NULL);
		}
		pthread_mutex_unlock(philo->dead_lock);
		if (ft_check_meals(philo))
			return (NULL);
		ft_take_forks(philo); // 2. Prendi le forchette
		ft_eat(philo); // 3. Mangia
		ft_release_forks(philo); // 4. Rilascia forchette
		ft_sleep(philo); // 5. Dormi
		ft_think(philo); // 6. Pensiero
	}
	return (NULL);
}

void	*ft_single_philo(t_philo *philo)
{
	size_t timestamp;

	ft_printf("0 1 has taken a fork\n");
	timestamp = ft_get_current_time(philo->program) - philo->start_time;
	ft_printf("%u 1 died\n", timestamp);
	return (NULL);
}

//4. Logging Sincronizzato:
// void	ft_log_action(t_philo *philo, char *action)
// {
// 	size_t timestamp;

// 	// pthread_mutex_lock(philo->dead_lock);
// 	// if (*(philo->dead) == 1)
// 	// {
// 	// 	pthread_mutex_unlock(philo->dead_lock);
// 	// 	return;
// 	// }
// 	pthread_mutex_lock(philo->write_lock);
// 	timestamp = ft_get_current_time(philo->program) - philo->start_time;
// 	ft_printf("%u %d %s\n", timestamp, philo->id, action);
// 	pthread_mutex_unlock(philo->write_lock);
// 	// pthread_mutex_unlock(philo->dead_lock);
// }

void	ft_log_action(t_philo *philo, char *action)
{
	size_t timestamp;

	pthread_mutex_lock(philo->dead_lock);
	if (*(philo->dead))
	{
		pthread_mutex_unlock(philo->dead_lock);
		return;
	}
	pthread_mutex_unlock(philo->dead_lock);

	pthread_mutex_lock(philo->write_lock);
	timestamp = ft_get_current_time(philo->program) - philo->start_time;
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

int	ft_usleep(size_t milliseconds, t_program *program)
{
	size_t	start; // funzione usleep che include il ciclo while per gestire interruzioni e tempo minimo

	start = ft_get_current_time(program);
	while ((ft_get_current_time(program) - start) < milliseconds)
		usleep(500); // funzione che sospende l'esecuzione del programma chiamante per un numero specificato di microsecondi. 500 corrisponde a 500 microsecondi, un buon compromesso tra precisione e overhead
	return (0);
}

size_t	ft_get_current_time(t_program *program)
{
	struct timeval	tv; // Struttura per salvare secondi e microsecondi
	
	if ( gettimeofday(&tv, NULL) == -1)
		ft_error_check("Error: gettimeofday failed", program, 2);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));  // Converte: 1. Secondi -> millisecondi (tv_sec * 1000) / 2. Microsecondi -> millisecondi (tv_usec / 1000) / Somma i due valori per ottenere il tempo totale in millisecondi
}
