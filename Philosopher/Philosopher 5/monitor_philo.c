/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:49:22 by vloddo            #+#    #+#             */
/*   Updated: 2025/05/19 19:40:58 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

// void	*ft_monitor(void *arg)
// {
// 	t_program	*program = (t_program *)arg;
// 	int			i;
// 	int			done;

// 	while (1)
// 	{
// 		i = 0;
// 		done = 0;
// 		while (i < program->num_philos)
// 		{		
// 			if (ft_check_death(&program->philos[i]))
// 			{
// 				ft_log_action_dead(&program->philos[i], "died");
// 				return (NULL);
// 			}
// 			pthread_mutex_lock(program->philos[i].meal_lock);
// 			if (program->philos[i].num_times_to_eat != -1 &&
// 				program->philos[i].meals_eaten >= program->philos[i].num_times_to_eat)
// 				done++;
// 			pthread_mutex_unlock(program->philos[i].meal_lock);
// 			i++;
// 		}
// 		if (done == program->num_philos)
// 		{
// 			pthread_mutex_lock(program->philos[0].write_lock);
// 			ft_printf("Each philosopher has eaten %d times\n", program->philos[0].num_times_to_eat);
// 			pthread_mutex_unlock(program->philos[0].write_lock);
// 			return (NULL);
// 		}
// 	}
// 	return (NULL);
// }

// void	*ft_monitor(void *arg)
// {
// 	t_program	*program = (t_program *)arg;
// 	int			i;
// 	int			all_eaten;

// 	while (1)
// 	{
// 		i = 0;
// 		all_eaten = 0;
// 		while (i < program->num_philos)
// 		{		
// 			if (ft_check_death(&program->philos[i]))
// 			{
// 				ft_log_action_dead(&program->philos[i], "died");
// 				return (NULL);
// 			}
// 			pthread_mutex_lock(program->philos[i].meal_lock);
// 			if (program->philos[i].num_times_to_eat != -1 &&
// 				program->philos[i].meals_eaten >= program->philos[i].num_times_to_eat)
// 				all_eaten++;
// 			pthread_mutex_unlock(program->philos[i].meal_lock);
// 			i++;
// 		}
// 		if (all_eaten == program->num_philos)
// 		{
// 			ft_all_eaten(program);
// 			return (NULL);
// 		}
// 	}
// 	return (NULL);
// }

// void	ft_all_eaten(t_program *program)
// {
// 		pthread_mutex_lock(program->philos[0].write_lock);
// 		ft_printf("Each philosopher has eaten %d times\n", program->philos[0].num_times_to_eat);
// 		pthread_mutex_unlock(program->philos[0].write_lock);
// }

void	ft_log_action_dead(t_philo *philo, char *action)
{
	size_t timestamp;

	pthread_mutex_lock(philo->dead_lock);
	if (*(philo->dead) == 1)
		philo->program->dead_flag = 1;
	pthread_mutex_unlock(philo->dead_lock);
	timestamp = ft_get_current_time(philo->program) - philo->start_time;
	pthread_mutex_lock(philo->write_lock);
	ft_printf("%u %d %s\n", timestamp, philo->id, action);
	pthread_mutex_unlock(philo->write_lock);
}


void    *ft_monitor(void *arg)
{
    t_program   *program = (t_program *)arg;
    int         i;

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
            
        usleep(1000);
    }
    return (NULL);
}

static int  ft_check_meals_completion(t_program *program)
{
    int i;
    int done;

    done = 0;
    i = 0;
    while (i < program->num_philos)
    {
        pthread_mutex_lock(program->philos[i].meal_lock);
        if (program->philos[i].num_times_to_eat != -1 &&
            program->philos[i].meals_eaten >= program->philos[i].num_times_to_eat)
            done++;
        pthread_mutex_unlock(program->philos[i].meal_lock);
        i++;
    }
    
    if (done == program->num_philos)
    {
        pthread_mutex_lock(program->philos[0].write_lock);
        ft_printf("Each philosopher ate %d times\n", 
                program->philos[0].num_times_to_eat);
        pthread_mutex_unlock(program->philos[0].write_lock);
        return (1);
    }
    return (0);
}