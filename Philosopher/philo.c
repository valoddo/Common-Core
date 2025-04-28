/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:49:22 by vloddo            #+#    #+#             */
/*   Updated: 2025/04/09 18:11:53 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	ft_check_input(int argc, char **argv)
{
	int	i;
	int	value;

	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		if ((value > 200 && i == 1) || ( value <= 0 && i != argc - 1))
			ft_error_check("Error: Values must be > 0 (except last one)\n", 2);
		i++;
	}
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

void init_program(t_program *program, char **argv, int argc)
{
    (void)argc;
    int i;
    
    program->dead_flag = 0;
    pthread_mutex_init(&program->dead_lock, NULL);
    pthread_mutex_init(&program->meal_lock, NULL);
    pthread_mutex_init(&program->write_lock, NULL);
    
    i = 0;
    while (i < 200) 
	{
        pthread_mutex_init(&program->forks[i], NULL);
        i++;
    }
}


void init_philos(t_program *program, char **argv, int num_philos)
{
    size_t start_time = get_current_time();
    int i;
    
    i = 0;
    while (i < num_philos) 
	{
        program->philos[i] = (t_philo)
		{
            .id = i + 1,
            .dead = &program->dead_flag,
            .l_fork = &program->forks[i],
            .r_fork = &program->forks[(i + 1) % num_philos],
            .write_lock = &program->write_lock,
            .dead_lock = &program->dead_lock,
            .meal_lock = &program->meal_lock,
            .time_to_die = ft_atoi(argv[2]),
            .time_to_eat = ft_atoi(argv[3]),
            .time_to_sleep = ft_atoi(argv[4]),
            .num_times_to_eat = (argc == 6) ? ft_atoi(argv[5]) : -1,
            .start_time = start_time,
            .last_meal = start_time,
            .meals_eaten = 0
        };
        i++;
    }
}

int	main(int argc, char **argv)
{
	t_program		program;
	int				num_of_philos;
	int				i;

	if (argc == 1 || argc < 5 || argc > 6)
		ft_error_check("Error: Insert valid number of Args\n", 2);
	ft_check_input(argc, argv);
	num_of_philos = ft_atoi(argv[1]);	// Parse args , get num_of_philos
	init_program(&program, argv, argc);
    init_philos(&program, argv, num_philos);

	return (0);
}
