/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:58:57 by vloddo            #+#    #+#             */
/*   Updated: 2025/03/11 13:58:58 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		ft_close_window(game);
	else if (keycode == KEY_D || keycode == ARROW_RIGHT)
		ft_movement(game, 0, 1);
	else if (keycode == KEY_A || keycode == ARROW_LEFT)
		ft_movement(game, 0, -1);
	else if (keycode == KEY_W || keycode == ARROW_UP)
		ft_movement(game, -1, 0);
	else if (keycode == KEY_S || keycode == ARROW_DOWN)
		ft_movement(game, 1, 0);
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
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
	if (target_tile == 'E')
	{
		if (game->tot_collectible == 0)
			ft_close_window(game);
		return ;
	}
	if (target_tile == 'C')
		ft_count_move(game, new_x, new_y);
	mlx_put_image_to_window(game->mlx, game->win, game->empty, \
							game->play_y * 32, game->play_x * 32);
	game->play_x = new_x;
	game->play_y = new_y;
	mlx_put_image_to_window(game->mlx, game->win, game->play, \
							new_y * 32, new_x * 32);
}

void	ft_count_move(t_game *game, int new_x, int new_y)
{
	game->tot_collectible--;
	game->map[new_x][new_y] = '0';
}

int	ft_close_window(t_game *game)
{
	mlx_destroy_image(game->mlx, game->empty);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->collect);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->play);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free_memory(game, 4);
	exit(0);
}
