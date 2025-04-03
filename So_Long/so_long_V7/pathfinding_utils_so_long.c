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

char	**ft_copy_map(t_game *game)
{
	char	**copy;
	int		i;

	i = 0;
	copy = ft_calloc((game->row + 1), sizeof(char *));
	if (!copy)
		return (NULL);
	while (game->map[i])
	{
		copy[i] = ft_strdup(game->map[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

t_position	ft_find_position(char **map, char c)
{
	t_position	pos;
	int			i;
	int			j;

	pos.x = -1;
	pos.y = -1;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				pos.x = i;
				pos.y = j;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (pos);
}

void	ft_flood_fill_loop(t_game *game, t_queue *queue, int *c, char target)
{
	t_position	pos;
	t_position	dir[4];
	int			i;

	dir[0] = (t_position){-1, 0};
	dir[1] = (t_position){1, 0};
	dir[2] = (t_position){0, -1};
	dir[3] = (t_position){0, 1};
	pos = dequeue(queue);
	if (pos.x < 0 || pos.y < 0 || pos.x >= game->row || pos.y >= game->col)
		return ;
	if (game->map_copy[pos.x][pos.y] == '1' || \
		game->map_copy[pos.x][pos.y] == 'X')
		return ;
	if (game->map_copy[pos.x][pos.y] == 'E' && target != 'E')
		return ;
	if (game->map_copy[pos.x][pos.y] == 'C')
		(*c)--;
	game->map_copy[pos.x][pos.y] = 'X';
	i = 0;
	while (i < 4)
	{
		enqueue(queue, (t_position){pos.x + dir[i].x, pos.y + dir[i].y});
		i++;
	}
}

void	ft_flood_fill(t_game *game, t_position start, int *c, char target)
{
	t_queue		*queue;

	queue = create_queue();
	enqueue(queue, start);
	while (!(queue->up == NULL))
	{
		ft_flood_fill_loop(game, queue, c, target);
	}
	free_queue(queue);
}

int	ft_is_reachable(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
