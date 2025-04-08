/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_so_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:58:57 by vloddo            #+#    #+#             */
/*   Updated: 2025/04/08 15:51:24 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_sprite_p(t_game *game, int keycode)
{
	if (keycode == KEY_D || keycode == ARROW_RIGHT)
		mlx_put_image_to_window(game->mlx, game->win, game->play_rs, \
			game->play_y * 32, game->play_x * 32);
	else if (keycode == KEY_A || keycode == ARROW_LEFT)
		mlx_put_image_to_window(game->mlx, game->win, game->play_ls, \
			game->play_y * 32, game->play_x * 32);
	else if (keycode == KEY_W || keycode == ARROW_UP)
		mlx_put_image_to_window(game->mlx, game->win, game->play_b, \
			game->play_y * 32, game->play_x * 32);
	else if (keycode == KEY_S || keycode == ARROW_DOWN)
		mlx_put_image_to_window(game->mlx, game->win, game->play_1, \
			game->play_y * 32, game->play_x * 32);
}

int	ft_animation(t_game *game)
{
	if (game->frame % 100000 == 0)
	{
		if (game->sprite_index == 0)
			game->sprite_index = 1;
		else
			game->sprite_index = 0;
		ft_render_map_body_and_p(game);
		ft_render_map_frame(game);
		ft_render_count(game);
	}
	game->frame++;
	return (0);
}
