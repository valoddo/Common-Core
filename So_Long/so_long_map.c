/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:59:07 by vloddo            #+#    #+#             */
/*   Updated: 2025/03/11 13:59:08 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_parsing(int argc, char **argv, t_game *game)
{
	char	*line;
	char	**copy_map;

	line = NULL;
	game->map = check_input(argc, argv, game, line);
	check_rect(game->map, game);
	check_cep(game->map, game, 0, 0);
	copy_map = make_matrix_solong(game->row, argv[1]);
	flood_fill(copy_map, game->map, game.map->start_p[0],
		game.map->start_p[1]);
	floodfill_check(copy_map, game, 0, 0);
	free_matrix(copy_map, game.map->rows);
	return (game.map->map_matrix);
}

void	ft_load_images(t_game *game)
{
	int	size;

	game->empty_img = mlx_xpm_file_to_image(game->mlx, EMPTY, &size, &size);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, WALL, &size, &size);
	game->collect_img = mlx_xpm_file_to_image(game->mlx, COLLECT, &size, &size);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, EXIT, &size, &size);
	game->player_img = mlx_xpm_file_to_image(game->mlx, PLAYER, &size, &size);
    if (!game->player_img || !game->wall_img || !game->empty_img || !game->exit_img) // Controllo se le immagini sono state caricate correttamente
	{
		write(2, "Error: Failed to load images\n", 29);
		exit(1);
	}
}

void ft_render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i]) // Cicla sulle righe della mappa
	{
		j = 0;
		while (game->map[i][j]) // Cicla sulle colonne della mappa
		{
			mlx_put_image_to_window(game->mlx, game->win, game->empty_img, j * 32, i * 32); // Disegna sempre il terreno per evitare artefatti grafici
			if (game->map[i][j] == '1')  // Parete
				mlx_put_image_to_window(game->mlx, game->win, game->wall_img, j * 32, i * 32);
			else if (game->map[i][j] == 'C')  // Giocatore
				 mlx_put_image_to_window(game->mlx, game->win, game->collect_img, j * 32, i * 32);
			else if (game->map[i][j] == 'E')  // Uscita
				mlx_put_image_to_window(game->mlx, game->win, game->exit_img, j * 32, i * 32);
			else if (game->map[i][j] == 'P')  // Giocatore
				mlx_put_image_to_window(game->mlx, game->win, game->player_img, j * 32, i * 32);
			j++;
		}
		i++;
	}
}
