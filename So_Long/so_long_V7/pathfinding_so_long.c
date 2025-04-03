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

void	ft_pathfinding_p(t_game *game)
{
	t_position	start;
	int			collectibles;

	collectibles = game->tot_collectible;
	game->map_copy = ft_copy_map(game);
	if (!game->map_copy)
		ft_error_check(game, 4, "Error: Failed to copy map\n", 7);
	start = ft_find_position(game->map_copy, 'P');
	if (start.x == -1 || start.y == -1)
	{
		free_map_copy(game);
		ft_error_check(game, 4, "Error: Player position not found\n", 7);
	}
	ft_flood_fill(game, start, &collectibles, 'C');
	if (collectibles != 0)
	{
		free_map_copy(game);
		ft_error_check(game, 4, "Error: Collectibles not reachable\n", 7);
	}
	free_map_copy(game);
}

void	ft_pathfinding_e(t_game *game)
{
	t_position	start;
	int			collectibles;

	collectibles = game->tot_collectible;
	game->map_copy = ft_copy_map(game);
	if (!game->map_copy)
		ft_error_check(game, 4, "Error: Failed to copy map\n", 7);
	start = ft_find_position(game->map_copy, 'P');
	ft_flood_fill(game, start, &collectibles, 'C');
	if (collectibles != 0)
	{
		free_map_copy(game);
		ft_error_check(game, 4, "Error: Collectibles not reachable\n", 7);
	}
	free_map_copy(game);
	game->map_copy = ft_copy_map(game);
	if (!game->map_copy)
		ft_error_check(game, 4, "Error: Failed to copy map\n", 7);
	ft_flood_fill(game, start, &collectibles, 'E');
	if (!ft_is_reachable(game->map_copy, 'E'))
	{
		free_map_copy(game);
		ft_error_check(game, 4, "Error: Exit is not reachable\n", 7);
	}
	free_map_copy(game);
}
