/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:49:22 by vloddo            #+#    #+#             */
/*   Updated: 2025/04/28 19:34:05 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	ft_check_input(t_program *program, int argc, char **argv)
{
	int	i;
	int	value;

	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		if ((value > 200 && i == 1) || ( value <= 0 && i != argc - 1))
			ft_error_check("Error: Check valid values\n", 2);
		i++;
	}
    program->num_philos = ft_atoi(argv[1]);
}

int	ft_atoi(char *argv)
{
	int		i;
	long	result;

	i = 0;
	while (argv[i] == ' ' || (argv[i] >= 9 && argv[i] <= 13))
		i++;
	if (argv[i] == '-')
		ft_error_check("Error: Negative numbers not allowed\n", 2);
	if (argv[i] == '+')
		i++;
	if (argv[i] < '0' || argv[i] > '9')
		ft_error_check("Error: Invalid number format\n", 2);
	result = 0;
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			ft_error_check("Error: Invalid number format\n", 2);
		result = result * 10 + (argv[i] - '0');
		if (result > INT_MAX)
			ft_error_check("Error: Number too large\n", 2);
		i++;
	}
	return ((int)result);
}

void	init_program(t_program *program)
{
    int i;
    
    program->dead_flag = 0;
    pthread_mutex_init(&program->dead_lock, NULL);
    pthread_mutex_init(&program->meal_lock, NULL);
    pthread_mutex_init(&program->write_lock, NULL);
    
    i = 0;
    while (i < program->num_philos) 
	{
        pthread_mutex_init(&program->forks[i], NULL);
        i++;
    }
}


void	init_philos(t_program *program, char **argv, int argc)
{
	int		i;
	size_t	current_time;

	current_time = get_current_time();
	i = 0;
	while (i < program->num_philos)
	{
		new_philo(program, argv, i, current_time);
		if (argc == 6)
			program->philos[i].num_times_to_eat = ft_atoi(argv[5]);
		else
			program->philos[i].num_times_to_eat = -1;
		i++;
	}
}


size_t	get_current_time(void)
{
	struct timeval	tv;

	if ( gettimeofday(&tv, NULL) == -1)
		ft_error_check("Error: gettimeofday failed\n", 2);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	new_philo(t_program *program, char **argv, int i, size_t current_time)
{
	program->philos[i] = (t_philo) // Assegnazione diretta della struct
	{
		.id = i + 1,
		.meals_eaten = 0,
		.dead = &program->dead_flag,
		.last_meal = current_time,
		.time_to_die = ft_atoi(argv[2]),
		.time_to_eat = ft_atoi(argv[3]),
		.time_to_sleep = ft_atoi(argv[4]),
		.start_time = current_time,
		.l_fork = &program->forks[i],
		.r_fork = &program->forks[(i + 1) % program->num_philos], // Modulo per circolarità
		.write_lock = &program->write_lock, // Mutex per operazioni di I/O
		.dead_lock = &program->dead_lock, // Mutex per lo stato di morte
		.meal_lock = &program->meal_lock,  // Mutex per i pasti
	};
}

int	main(int argc, char **argv)
{
	t_program		program;
	int				i;

	if (argc == 1 || argc < 5 || argc > 6)
		ft_error_check("Error: Insert valid number of args\n", 2);
	ft_check_input(&program, argc, argv);
	init_program(&program);
    init_philos(&program, argv, argc);
	return (0);
}