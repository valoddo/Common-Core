/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:49:22 by vloddo            #+#    #+#             */
/*   Updated: 2025/05/17 19:22:14 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

// void *ft_monitor(void *arg)
// {
//     t_program *program = (t_program *)arg;
//     int all_ate;
//     size_t current_time;
//     int i;

//     while (1)
//     {
//         all_ate = 1;
//         i = 0;
//         while (i < program->num_philos)
//         {
//             pthread_mutex_lock(&program->meal_lock);
//             current_time = ft_get_current_time(program);
//             if (current_time - program->philos[i].last_meal >= program->philos[i].time_to_die)
//             {
//                 pthread_mutex_lock(&program->dead_lock);
//                 program->dead_flag = 1;
//                 pthread_mutex_unlock(&program->dead_lock);
//                 ft_log_action(&program->philos[i], "died");
//                 pthread_mutex_unlock(&program->meal_lock);
//                 return (NULL);
//             }
//             if (program->philos[i].num_times_to_eat != -1 && 
//                 program->philos[i].meals_eaten < program->philos[i].num_times_to_eat)
//                 all_ate = 0;
//             pthread_mutex_unlock(&program->meal_lock);
//             i++;
//         }
//         if (all_ate)
//         {
//             pthread_mutex_lock(&program->dead_lock);
//             program->dead_flag = 1;
//             pthread_mutex_unlock(&program->dead_lock);
//             return (NULL);
//         }
//         ft_usleep(1, program);
//     }
//     return (NULL);
// }

void	*ft_monitor(void *arg)
{
	t_program	*program = (t_program *)arg;
	int			i;

	while (1)
	{
		i = 0;
		while (i < program->num_philos)
		{
			if (ft_check_death(&program->philos[i]) == 1) // 1. Controllo morte
			{
                
                ft_log_action_dead(&program->philos[i], "died");
				return (NULL);
			}
            i++;
            //ft_usleep(1, program);
        }
    }
    return (NULL);
}


