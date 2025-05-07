/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:49:35 by vloddo            #+#    #+#             */
/*   Updated: 2025/05/07 16:49:30 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h> //libreria dei thread e mutex
# include <sys/time.h> // libreria per gettimeofday
# include <limits.h>

typedef struct	s_program t_program;

typedef struct	s_philo
{
	pthread_t		thread;
	int				id;
	int				meals_eaten;
	int				num_times_to_eat;
	int				*dead;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}	t_philo;

struct	s_program
{
	int				dead_flag;
	int				num_philos;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	forks[200];    // Array fisso per 200 mutex
	t_philo			philos[200];   // Array fisso per 200 filosofi
};

// error_philo.c
int		ft_error_check(char *msg, int free_level);
// void	ft_putstr(char *str);
// void	ft_free_memory(t_philo *philo, int i);

// philo.c
void	ft_check_input(int argc, char **argv);
int		ft_atoi(char *argv);
void	ft_init_philos(t_program *program, char **argv, int argc);
size_t	ft_get_current_time(void);
void	ft_new_philo(t_program *program, char **argv, int i, size_t current_time);
void	ft_init_program(t_program *program, char **argv);
int		ft_usleep(size_t milliseconds);


// philo_routine.c
void	*ft_philo_routine(void *arg);
int		ft_check_death(t_philo *philo);
int		ft_check_meals(t_philo *philo);
void	ft_take_forks(t_philo *philo);
void	ft_release_forks(t_philo *philo);
void	ft_eat(t_philo *philo);
void	ft_philo_sleep(t_philo *philo);
void	ft_think(t_philo *philo);
void	ft_log_action(t_philo *philo, char *action);

# endif
