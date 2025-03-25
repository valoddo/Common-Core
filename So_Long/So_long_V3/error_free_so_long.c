/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:58:48 by vloddo            #+#    #+#             */
/*   Updated: 2025/03/11 13:58:50 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_check(t_game *game, int free_level, char *msg, int exit_code)
{
	ft_free_memory(game, free_level);
	ft_error(msg, exit_code);
}

void	ft_free_memory(t_game *game, int i)
{
	while (i <= 5)
	{
		if ( i == 5)
			free(game);
		else if ( i == 4)
			free_map(game);
		i++;
	}
}

void	free_map(t_game *game)
{
	int	i;
	
	i = 0;
	if (game && game->map)
	{
		while (i < game->row)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
}

void	ft_error(char *str, int i)
{
	if (i == 5)
		write(1, "Usage: ./game <map.ber>\n", 25);
	else if (i == 6)
		write(1, "Error: No such file or directory\n", 34);
	else if (i == 7)
		write(1, "Error: creating map\n", 34);
	else if (i == 7)
		write(1, "Error: insert valid map\n", 25);
	else if (i == 8)
		write(1, "Error: insert valid rectangular map\n", 37);
	else if (i == 9)
		write(2, "Error: Failed to load images\n", 29);
	else if (i == 10)
		write(2, "Error: Impossible to create the window\n", 37);
	{
		perror(str);
		exit(i);
	}
	exit(EXIT_FAILURE);
}
