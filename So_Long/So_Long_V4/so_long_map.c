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

char	**ft_parsing(int argc, char **argv, t_game *game)
{
	if (argc != 2)
		ft_error_check(game, 5, "Usage: ./game <map.ber>\n", 5);
	if (ft_strlen(argv[1]) >= 4 && ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber") != 0)
		ft_error_check(game, 5, "Usage: ./game <map.ber>\n", 5);
	game->map = ft_fill_map(argv, game);
	ft_map_check_frame (game);
	ft_map_check_player(game);
	ft_map_check_exit(game);
	ft_map_check_collectible(game);
	ft_map_check_field(game);
	return (game->map);
}

char **ft_fill_map(char **argv, t_game *game)
{
    int fd;

    game->map = NULL;
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        ft_error_check(game, 5, "Error: No such file or directory\n", 6);
    if (!read_and_process_lines(game, fd))
    {
        close(fd);
        ft_error_check(game, 4, "Error: insert valid map\n", 7);
    }
    close(fd);
    game->map = terminate_map_array(game);
    if (!game->map)
        ft_error_check(game, 4, "Error: insert valid map\n", 7);
    return (game->map);
}

int read_and_process_lines(t_game *game, int fd)
{
    char *text;
    char **temp;

    text = get_next_line(fd);
    while (text)
    {
        game->row++;
        temp = process_line(game, text, NULL);
        if (!temp)
        {
            free(text);
            return (0);
        }
        free(game->map);
        game->map = temp;
        free(text);
        text = get_next_line(fd);
    }
    return (1);
}

char	**process_line(t_game *game, char *text, char **temp)
{
	int		i;
	size_t	len;
	
	len = ft_strlen(text);
	if (len > 0 && text[len - 1] == '\n')
	text[len - 1] = '\0';
	temp = ft_calloc(game->row, sizeof(char *));
	if (!temp)
		return (NULL);
	i = -1;
	while (++i < game->row - 1)
		temp[i] = game->map[i];
	temp[game->row - 1] = ft_calloc((ft_strlen(text) + 1), sizeof(char));
	if (!temp[game->row - 1])
	{
		free(temp);
		return (NULL);
	}
	ft_strcpy(temp[game->row - 1], text);
	return (temp);
}

char	**terminate_map_array(t_game *game)
{
	char	**temp;
	int		i;
	
	temp = ft_calloc((game->row + 1), sizeof(char *));
	if (!temp)
	return (NULL);
	i = -1;
	while (++i < game->row)
		temp[i] = game->map[i];
	temp[game->row] = NULL;
	free(game->map);	
	return (temp);
}

void	ft_load_images(t_game *game)
{
	int	size;

	game->empty_img = mlx_xpm_file_to_image(game->mlx, EMPTY, &size, &size);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, WALL, &size, &size);
	game->collect_img = mlx_xpm_file_to_image(game->mlx, COLLECT, &size, &size);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, EXIT, &size, &size);
	game->player_img = mlx_xpm_file_to_image(game->mlx, PLAYER, &size, &size);
	if (!game->player_img || !game->wall_img || !game->empty_img || !game->exit_img)
		ft_error_check(game, 4, "Error: Failed to load images\n", 9);
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

// char	**ft_fill_map(char **argv, t_game *game)
// {
// 	int		fd;
// 	char	*text;
// 	char	**temp;

// 	game->map = NULL;
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 		ft_error_check(game, 5, "Error: No such file or directory\n", 6);
// 	text = get_next_line(fd);
// 	while (text)
// 	{
// 		game->row++;
// 		temp = process_line(game, text, NULL);
// 		if (!temp)
// 		{
// 			free(text);
// 			close(fd);
// 			ft_error_check(game, 4, "Error: insert valid map\n", 7);
// 		}
// 		free(game->map);
// 		game->map = temp;
// 		free(text);
// 		text = get_next_line(fd);
// 	}
// 	close(fd);
// 	game->map = terminate_map_array(game);
// 	if (!game->map)
// 		ft_error_check(game, 4, "Error: insert valid map\n", 7);
// 	return (game->map);
// }