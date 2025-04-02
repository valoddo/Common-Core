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

void	ft_init_window(t_game *game)
{
	int  width;// 32 è la dimensione di un tile
	int height;

	width = game->col * 32;
	height = game->row * 32;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (!game->win)
		ft_error_check(game, 4, "Error: Impossible to create the window\n", 10);
	ft_load_images(game);  // Carica le immagini
	ft_render_map(game);   // Renderizza la mappa // Imposta i gestori per gli eventi
	mlx_hook(game->win, 2, 1L << 0, ft_key_hook, game);  // Gestisci tasti (KeyPress)
	mlx_hook(game->win, 17, 1L << 17, ft_close_window, game);  // Gestisci chiusura finestra (DestroyNotify)
}

void	ft_load_images(t_game *game)
{
	int	size;

	game->empty_img = mlx_xpm_file_to_image(game->mlx, EMPTY, &size, &size);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, WALL, &size, &size);
	game->collect_img = mlx_xpm_file_to_image(game->mlx, COLLECT, &size, &size);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, EXIT, &size, &size);
	game->exit_1_img = mlx_xpm_file_to_image(game->mlx, EXIT_1, &size, &size);
	game->player_img = mlx_xpm_file_to_image(game->mlx, PLAYER, &size, &size);
	game->player_1_img = mlx_xpm_file_to_image(game->mlx, PLAYER_1, &size, &size);
	game->player_back_img = mlx_xpm_file_to_image(game->mlx, PLAYER_BACK, &size, &size);
	game->player_back_1_img = mlx_xpm_file_to_image(game->mlx, PLAYER_BACK_1, &size, &size);
	game->player_lside_img = mlx_xpm_file_to_image(game->mlx, PLAYER_LSIDE, &size, &size);
	game->player_lside_1_img = mlx_xpm_file_to_image(game->mlx, PLAYER_LSIDE_1, &size, &size);
	game->player_rside_img = mlx_xpm_file_to_image(game->mlx, PLAYER_RSIDE, &size, &size);
	game->player_rside_1_img = mlx_xpm_file_to_image(game->mlx, PLAYER_RSIDE_1, &size, &size);
	if (!game->player_img || !game->wall_img || !game->empty_img || !game->exit_img)
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
			mlx_put_image_to_window(game->mlx, game->win, game->empty_img, j * 32, i * 32);
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall_img, j * 32, i * 32);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collect_img, j * 32, i * 32);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_img, j * 32, i * 32);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->player_img, game->player_y * 32, game->player_x * 32);
}

int	main(int argc, char **argv)
{
	t_game *game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (1);
	game->mlx = mlx_init(); // Inizializza la connessione MLX (FONDAMENTALE) 
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
