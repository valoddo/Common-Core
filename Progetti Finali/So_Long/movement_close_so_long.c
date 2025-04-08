/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_close_so_long.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:58:57 by vloddo            #+#    #+#             */
/*   Updated: 2025/04/08 15:55:58 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		ft_close_window(game);
	else if (keycode == KEY_D || keycode == ARROW_RIGHT)
	{
		ft_movement(game, 0, 1);
		ft_sprite_p(game, keycode);
	}
	else if (keycode == KEY_A || keycode == ARROW_LEFT)
	{
		ft_movement(game, 0, -1);
		ft_sprite_p(game, keycode);
	}
	else if (keycode == KEY_W || keycode == ARROW_UP)
	{
		ft_movement(game, -1, 0);
		ft_sprite_p(game, keycode);
	}
	else if (keycode == KEY_S || keycode == ARROW_DOWN)
	{
		ft_movement(game, 1, 0);
		ft_sprite_p(game, keycode);
	}
	return (0);
}

void	ft_movement(t_game *game, int x, int y)
{
	int		new_x;
	int		new_y;
	char	target_tile;

	new_x = game->play_x + x;
	new_y = game->play_y + y;
	if (new_x < 0 || new_y < 0 || new_x >= game->row || new_y >= game->col)
		return ;
	target_tile = game->map[new_x][new_y];
	if (target_tile == '1')
		return ;
	if (target_tile == 'N')
		ft_close_window(game);
	if (target_tile == 'E')
	{
		if (game->tot_collectible == 0)
			ft_close_window(game);
		return ;
	}
	if (target_tile == 'C' || target_tile == '0' )
		ft_count_move(game, new_x, new_y, target_tile);
	mlx_put_image_to_window(game->mlx, game->win, game->empty, \
							game->play_y * 32, game->play_x * 32);
	game->play_x = new_x;
	game->play_y = new_y;
}

void	ft_count_move(t_game *game, int new_x, int new_y, char target)
{
	if (target == 'C')
	{
		game->tot_collectible--;
		game->map[new_x][new_y] = '0';
	}
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
}

int	ft_close_window(t_game *game)
{
	mlx_destroy_image(game->mlx, game->empty);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->collect);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->play);
	mlx_destroy_image(game->mlx, game->enemy_n[0]);
	mlx_destroy_image(game->mlx, game->enemy_n[1]);
	mlx_destroy_image(game->mlx, game->exit_1);
	mlx_destroy_image(game->mlx, game->play_1);
	mlx_destroy_image(game->mlx, game->play_b);
	mlx_destroy_image(game->mlx, game->play_b_1);
	mlx_destroy_image(game->mlx, game->play_ls);
	mlx_destroy_image(game->mlx, game->play_ls_1);
	mlx_destroy_image(game->mlx, game->play_rs);
	mlx_destroy_image(game->mlx, game->play_rs_1);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free_memory(game, 4);
	exit(0);
}

void	ft_render_count(t_game *game)
{
	char	*moves;

	mlx_put_image_to_window(game->mlx, game->win, game->wall, \
							0 * 32, 0 * 32);
	moves = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, moves);
	free(moves);
}
