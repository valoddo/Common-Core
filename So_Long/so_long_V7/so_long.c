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

char	**ft_parsing(int argc, char **argv, t_game *game)
{
	if (argc != 2)
		ft_error_check(game, 5, "Usage: ./game <map.ber>\n", 5);
	if (ft_strlen(argv[1]) >= 4 && \
		ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber") != 0)
		ft_error_check(game, 5, "Usage: ./game <map.ber>\n", 5);
	game->map = ft_fill_map(argv, game);
	ft_map_check_frame (game);
	ft_map_check_player(game);
	ft_map_check_exit(game);
	ft_map_check_collectible(game);
	ft_map_check_field(game);
	ft_pathfinding_p(game);
	ft_pathfinding_e(game);
	game->moves = 0;
	return (game->map);
}

void	ft_init_window(t_game *game)
{
	int	width;
	int	height;

	width = game->col * 32;
	height = game->row * 32;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (!game->win)
		ft_error_check(game, 4, "Error: Impossible to create the window\n", 10);
	ft_load_images(game);
	ft_render_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->play, \
							game->play_y * 32, game->play_x * 32);
	mlx_hook(game->win, 2, 1L << 0, ft_key_hook, game);
	mlx_hook(game->win, 17, 1L << 17, ft_close_window, game);
}

void	ft_load_images(t_game *game)
{
	int	size;

	game->empty = mlx_xpm_file_to_image(game->mlx, EMPTY, &size, &size);
	game->wall = mlx_xpm_file_to_image(game->mlx, WALL, &size, &size);
	game->collect = mlx_xpm_file_to_image(game->mlx, COLLECT, &size, &size);
	game->exit = mlx_xpm_file_to_image(game->mlx, EXIT, &size, &size);
	game->play = mlx_xpm_file_to_image(game->mlx, PLAY, &size, &size);
	if (!game->play || !game->wall || !game->empty || !game->exit)
		ft_error_check(game, 4, "Error: Failed to load images\n", 9);
}

void	ft_render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			mlx_put_image_to_window(game->mlx, game->win, game->empty, \
									j * 32, i * 32);
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, \
										j * 32, i * 32);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collect, \
										j * 32, i * 32);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit, \
										j * 32, i * 32);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (1);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free(game);
		ft_putstr("Error: MLX initialization failed\n");
		return (1);
	}
	game->map = ft_parsing(argc, argv, game);
	ft_init_window(game);
	mlx_loop(game->mlx);
	return (0);
}
