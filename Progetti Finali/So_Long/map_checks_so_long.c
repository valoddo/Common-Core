/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:59:15 by vloddo            #+#    #+#             */
/*   Updated: 2025/03/11 13:59:17 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_check_frame(t_game *game)
{
	int	i;

	game->col = ft_strlen(game->map[0]);
	i = 1;
	while (i < game->row)
	{
		if (ft_strlen(game->map[i]) != (size_t)game->col)
			ft_error_check(game, 4, "Error: insert valid rectangular map\n", 8);
		i++;
	}
	i = 0;
	while (i < game->row)
	{
		if (game->map[i][0] != '1' || game->map[i][game->col - 1] != '1' )
			ft_error_check(game, 4, "Error: insert valid rectangular map\n", 8);
		i++;
	}
	i = 0;
	while (i < game->col)
	{
		if (game->map[0][i] != '1' || game->map[game->row - 1][i] != '1')
			ft_error_check(game, 4, "Error: insert valid rectangular map\n", 8);
		i++;
	}
}

void	ft_map_check_player(t_game *game)
{
	int	x;
	int	y;
	int	p;

	p = 0;
	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'P')
			{
				game->play_x = x;
				game->play_y = y;
				p += 1;
			}
			y++;
		}
		x++;
	}
	if (p != 1)
		ft_error_check(game, 4, "Error: insert one Player\n", 7);
}

void	ft_map_check_exit(t_game *game)
{
	int	i;
	int	j;
	int	e;

	e = 0;
	i = 1;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
			{
				e += 1;
				game->exit_x = i;
				game->exit_y = j;
			}
			j++;
		}
		i++;
	}
	if (e != 1)
		ft_error_check(game, 4, "Error: insert one Exit\n", 7);
}

void	ft_map_check_collectible(t_game *game)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = 1;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				c += 1;
			j++;
		}
		i++;
	}
	game->tot_collectible = c;
	if (c <= 0)
		ft_error_check(game, 4, "Error: insert at least one Collectible\n", 7);
}

void	ft_map_check_field(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if ((game->map[i][j] != 'P') && (game->map[i][j] != 'E') && \
				(game->map[i][j] != 'C') && (game->map[i][j] != '0') && \
				(game->map[i][j] != 'N') && (game->map[i][j] != '1'))
				ft_error_check(game, 4, "Error: insert valid Field\n", 7);
			j++;
		}
		i++;
	}
}
