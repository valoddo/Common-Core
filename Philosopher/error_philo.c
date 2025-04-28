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

int	ft_error_check(char *msg, int free_level)
{
    //ft_free_memory(philo, free_level);
    ft_putstr(msg);
    exit (free_level);
}
void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

/*void	ft_free_memory(t_philo *philo, int i) // funzione free per la struttura
{
	while (i <= 5)
	{
		if ( i == 2)
			free(philo);
	}
} */