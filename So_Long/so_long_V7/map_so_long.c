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

char	**ft_fill_map(char **argv, t_game *game)
{
	int	fd;

	game->map = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error_check(game, 5, "Error: No such file or directory\n", 6);
	if (ft_is_empty_file(fd))
	{
		close(fd);
		ft_error_check(game, 4, "Error: Map file empty\n", 7);
	}
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

int	ft_is_empty_file(int fd)
{
	char	buffer[1];
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, 1);
	lseek(fd, 0, SEEK_SET);
	return (bytes_read <= 0);
}

int	read_and_process_lines(t_game *game, int fd)
{
	char	*text;
	char	**temp;

	text = get_next_line(fd);
	while (text)
	{
		game->row++;
		temp = process_line(game, text, temp);
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
