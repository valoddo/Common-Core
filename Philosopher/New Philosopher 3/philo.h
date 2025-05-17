/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:49:35 by vloddo            #+#    #+#             */
/*   Updated: 2025/05/17 18:37:59 by vloddo           ###   ########.fr       */
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
	int				meals_eaten; // pasti consumati
	int				num_times_to_eat; // pasti richiesti, se -1 vuol dire che non e stato dato un numero di pasti ed e infinito
	int				*dead; // flag, se 1 vuol dire che il philo e morto
	size_t			last_meal; // tempo dell'ultimo pasto
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	t_program		*program;
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
void	ft_error_check(char *msg, t_program *program, int exit_code);
void	ft_clean_program(t_program *program);

// philo.c
void	ft_check_input(int argc, char **argv, t_program *program);
int		ft_atoi(char *argv, t_program *program);
void	ft_init_philos(t_program *program, char **argv, int argc);
size_t	ft_get_current_time(t_program *program);
void	ft_new_philo(t_program *program, char **argv, int i, size_t current_time);
void	ft_init_program(t_program *program);
int		ft_usleep(size_t milliseconds, t_program *program);


// philo_routine.c
void	*ft_philo_routine(void *arg);
void	*ft_single_philo(t_philo *philo);
int		ft_check_death(t_philo *philo);
int		ft_check_meals(t_philo *philo);
void	ft_take_forks(t_philo *philo);
void	ft_release_forks(t_philo *philo);
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);
void	ft_log_action(t_philo *philo, char *action);
void	ft_log_action_dead(t_philo *philo, char *action);

// monitor_philo.c
void	*ft_monitor(void *arg);

//valgrind --tool=helgrind ./philo 5 200 100 100  

# endif
