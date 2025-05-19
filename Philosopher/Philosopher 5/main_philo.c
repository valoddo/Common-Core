/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:49:22 by vloddo            #+#    #+#             */
/*   Updated: 2025/05/19 19:36:33 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

// int	main(int argc, char **argv)
// {
// 	t_program	program;
// 	pthread_t	monitor;
// 	int			i;

// 	if (argc < 5 || argc > 6)
// 		ft_error_check("Error: Invalid number of args", NULL, 2);
// 	program.num_philos = ft_atoi(argv[1], &program);
// 	ft_check_input(argc, argv, &program);
// 	ft_init_program(&program);
// 	ft_init_philos(&program, argv, argc);
// 	i = 0;
// 	while (i < program.num_philos)
// 	{
// 		if (pthread_create(&program.philos[i].thread, NULL, ft_philo_routine, &program.philos[i]) != 0)
// 			ft_error_check("Error: Thread creation failed", &program, 2);
// 		i++;
// 	}
// 	if (pthread_create(&monitor, NULL, ft_monitor, (void *)&program) != 0)
// 		ft_error_check("Error: Monitor thread creation failed", &program, 2);
// 	i = 0;
// 	while (i < program.num_philos)
// 	{
// 		pthread_join(program.philos[i].thread, NULL);
// 		i++;
// 	}
// 	pthread_join(monitor, NULL);
// 	ft_clean_program(&program);
// 	return (0);
// }


// void	ft_create_thread(t_program *program)
// {
// 	pthread_t	monitor;
// 	int			i;

// 	i = 0;
// 	while (i < program.num_philos)
// 	{
// 		if (pthread_create(&program.philos[i].thread, NULL, ft_philo_routine, &program.philos[i]) != 0)
// 			ft_error_check("Error: Thread creation failed", &program, 2);
// 		i++;
// 	}
// 	if (pthread_create(&monitor, NULL, ft_monitor, (void *)&program) != 0)
// 		ft_error_check("Error: Monitor thread creation failed", &program, 2);
// 	i = 0;
// 	while (i < program.num_philos)
// 	{
// 		pthread_join(program.philos[i].thread, NULL);
// 		i++;
// 	}
// 	pthread_join(monitor, NULL);   
// }



// void	ft_create_threads(t_program *program, pthread_t *monitor)
// {
// 	int	i;

// 	i = 0;
// 	while (i < program->num_philos) // Corretto . con ->
// 	{
// 		if (pthread_create(&program->philos[i].thread, NULL, 
// 				ft_philo_routine, &program->philos[i]) != 0)
// 			ft_error_check("Error: Thread creation failed", program, 2); // Rimosso & davanti a program
// 		i++;
// 	}
// 	if (pthread_create(monitor, NULL, ft_monitor, (void *)program) != 0) // Cast corretto a void*
// 		ft_error_check("Error: Monitor thread creation failed", program, 2);
// }

// void	ft_join_threads(t_program *program, pthread_t monitor)
// {
// 	int	i;

// 	i = 0;
// 	while (i < program->num_philos)
// 	{
// 		pthread_join(program->philos[i].thread, NULL);
// 		i++;
// 	}
// 	pthread_join(monitor, NULL); // Usa la variabile locale passata
// }

// int	main(int argc, char **argv)
// {
// 	t_program	program;
// 	pthread_t	monitor; // Variabile locale come nell'originale

// 	if (argc < 5 || argc > 6)
// 		ft_error_check("Error: Invalid number of args", NULL, 2);
// 	program.num_philos = ft_atoi(argv[1], &program);
// 	ft_check_input(argc, argv, &program);
// 	ft_init_program(&program);
// 	ft_init_philos(&program, argv, argc);
// 	ft_create_threads(&program, &monitor); // Passa l'indirizzo del monitor
// 	ft_join_threads(&program, monitor); // Passa il monitor per valore
// 	ft_clean_program(&program);
// 	return (0);
// }

void    ft_create_threads(t_program *program)
{
    int         i;
    pthread_t   monitor;

    i = -1;
    while (++i < program->num_philos)
    {
        if (pthread_create(&program->philos[i].thread, NULL, 
            ft_philo_routine, &program->philos[i]) != 0)
            ft_error_check("Error: Thread creation failed", program, 2);
    }
    
    if (pthread_create(&monitor, NULL, ft_monitor, program) != 0)
        ft_error_check("Error: Monitor thread creation failed", program, 2);
    
    // Salva il thread monitor nell'ultimo elemento dei filosofi (hack)
    program->philos[program->num_philos - 1].thread = monitor;
}

void    ft_join_threads(t_program *program)
{
    int i;
    pthread_t monitor;

    i = -1;
    while (++i < program->num_philos - 1) // Escludi l'ultimo "filosofo"
        pthread_join(program->philos[i].thread, NULL);
    
    // Recupera il thread monitor dall'ultimo elemento
    monitor = program->philos[program->num_philos - 1].thread;
    pthread_join(monitor, NULL);
}

int	main(int argc, char **argv)
{
	t_program	program;

	if (argc < 5 || argc > 6)
		ft_error_check("Error: Invalid number of args", NULL, 2);
	program.num_philos = ft_atoi(argv[1], &program);
	ft_check_input(argc, argv, &program);
	ft_init_program(&program);
	ft_init_philos(&program, argv, argc);
	ft_create_threads(&program);
	ft_join_threads(&program);
	ft_clean_program(&program);
	return (0);
}
