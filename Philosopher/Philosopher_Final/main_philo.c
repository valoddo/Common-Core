/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:49:22 by vloddo            #+#    #+#             */
/*   Updated: 2025/05/20 13:51:14 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_program	program;
	pthread_t	monitor;
	int			i;

	if (argc < 5 || argc > 6)
		ft_error_check("Error: Invalid number of args", NULL, 2);
	program.num_philos = ft_atoi(argv[1], &program);
	ft_check_input(argc, argv, &program);
	ft_init_program(&program);
	ft_init_philos(&program, argv, argc);
	i = -1;
	while (++i < program.num_philos)
	{
		if (pthread_create(&program.philos[i].thread, NULL, \
			ft_philo_routine, &program.philos[i]) != 0)
			ft_error_check("Error: Thread creation failed", &program, 2);
	}
	if (pthread_create(&monitor, NULL, ft_monitor, (void *)&program) != 0)
		ft_error_check("Error: Monitor thread creation failed", &program, 2);
	i = -1;
	while (++i < program.num_philos)
		pthread_join(program.philos[i].thread, NULL);
	pthread_join(monitor, NULL);
	ft_clean_program(&program);
	return (0);
}
