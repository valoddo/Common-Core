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

void	ft_map_check(t_game *game)
{
	int	i;

	game->col = ft_strlen(game->map[0]);
	i = 1;
	while (i < game->row)
	{
		if (ft_strlen(game->map[i]) != (size_t)game->col)
			ft_error_check(game, 4, "Error rectangular map", 8);
		i++;
	}
	i = 0;
	while (i < game->row)
	{
		if (game->map[i][0] != '1' || game->map[i][game->col - 1] != '1')
			ft_error_check(game, 4, "Error map borders", 8);
		i++;
	}
	i = 0;
	while (i < game->col)
	{
		if (game->map[0][i] != '1' || game->map[game->row - 1][i] != '1')
			ft_error_check(game, 4, "Error map borders", 8);
		i++;
	}
}

