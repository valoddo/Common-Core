/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:49:22 by vloddo            #+#    #+#             */
/*   Updated: 2025/05/16 19:17:13 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	ft_check_input(int argc, char **argv, t_program *program)
{
	int	i;
	int	value;

	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i], program);
		if ((value > 200 && i == 1) || ( value <= 0 && i != 5))
			ft_error_check("Error: Check valid values", program, 2);
		i++;
	}
}

int	ft_atoi(char *argv, t_program *program)
{
	int		i;
	long	result;

	i = 0;
	while (argv[i] == ' ' || (argv[i] >= 9 && argv[i] <= 13))
		i++;
	if (argv[i] == '-')
		ft_error_check("Error: Negative numbers not allowed", program, 2);
	if (argv[i] == '+')
		i++;
	result = 0;
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			ft_error_check("Error: Invalid number format", program, 2);
		result = result * 10 + (argv[i] - '0');
		if (result > INT_MAX)
			ft_error_check("Error: Number too large", program, 2);
		i++;
	}
	return ((int)result);
}

void	ft_init_philos(t_program *program, char **argv, int argc)
{
	int		i;
	size_t	current_time;
	
	current_time = ft_get_current_time(program);
	i = 0;
	while (i < program->num_philos)
	{
		ft_new_philo(program, argv, i, current_time);
		if (argc == 6)
			program->philos[i].num_times_to_eat = ft_atoi(argv[5], program);
		else
			program->philos[i].num_times_to_eat = -1;
		i++;
	}
}

void	ft_new_philo(t_program *program, char **argv, int i, size_t current_time)
{
	program->philos[i] = (t_philo) // Assegnazione diretta della struct, I filosofi vengono inizializzati direttamente nell'array philos senza allocazione dinamica
	{
		.id = i + 1,
		.meals_eaten = 0,
		.dead = &program->dead_flag,
		.last_meal = current_time,
		.time_to_die = ft_atoi(argv[2], program),
		.time_to_eat = ft_atoi(argv[3], program),
		.time_to_sleep = ft_atoi(argv[4], program),
		.start_time = current_time,
		.l_fork = &program->forks[i],
		.r_fork = &program->forks[(i + 1) % program->num_philos], // Modulo per circolarità
		.write_lock = &program->write_lock, // Mutex per operazioni di I/O
		.dead_lock = &program->dead_lock, // Mutex per lo stato di morte
		.meal_lock = &program->meal_lock,  // Mutex per i pasti
		.program = program, //set il puntatore program
	};
}

void	ft_init_program(t_program *program)
{
	int i; // i mutex negli array forks e quelli singoli (dead_lock, meal_lock, write_lock) sono inizializzati tramite pthread_mutex_init, ma la loro memoria è gestita staticamente dalla struttura t_program.
	
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

int	main(int argc, char **argv)
{
	t_program	program;
	pthread_t	monitor;  // dichiarazione del thread monitor
	int			i;

	if (argc < 5 || argc > 6)
		ft_error_check("Error: Invalid number of args", NULL, 2);
	program.num_philos = ft_atoi(argv[1], &program);
	ft_check_input(argc, argv, &program);
	ft_init_program(&program);
	ft_init_philos(&program, argv, argc);
	i = 0;
	while (i < program.num_philos)
	{
		if (pthread_create(&program.philos[i].thread, NULL, ft_philo_routine, &program.philos[i]) != 0)
			ft_error_check("Error: Thread creation failed", &program, 2);
		i++;
	}
	if (pthread_create(&monitor, NULL, ft_monitor, (void *)&program) != 0)
		ft_error_check("Error: Monitor thread creation failed", &program, 2);
	i = 0;
	while (i < program.num_philos)
	{
		pthread_join(program.philos[i].thread, NULL);
		i++;
	}
	pthread_join(monitor, NULL);
	ft_clean_program(&program);
	return (0);
}

// Il codice evita correttamente malloc grazie a:
// Array statici nella struttura t_program.
// Controllo dell'input per rispettare la dimensione degli array.
// Inizializzazione diretta delle strutture.