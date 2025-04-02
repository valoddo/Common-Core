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
	ft_pathfinding(game);
	game->moves = 0; // INIZIALIZZA CONTATORE MOSSE
	return (game->map);
}

char	**ft_fill_map(char **argv, t_game *game)
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

int	read_and_process_lines(t_game *game, int fd)
{
	char	*text;
	char	**temp;

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

