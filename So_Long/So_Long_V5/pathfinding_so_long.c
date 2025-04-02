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

static char	**ft_copy_map(t_game *game)
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

static t_position	ft_find_position(char **map, char c)
{
	t_position	pos;
	int			i;

	pos.x = -1;
	pos.y = -1;
	i = 0;
	while (map[i])
	{
		int j = 0;
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

static void	ft_flood_fill(t_game *game, t_position start, int *collectibles, char target)
{
	t_queue		*queue;
	t_position	directions[] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
	t_position	current;
	int			i;

	queue = create_queue();
	enqueue(queue, start);
	while (!(queue->front == NULL))
	{
		current = dequeue(queue);
		if (current.x < 0 || current.y < 0 || current.x >= game->row || current.y >= game->col) // Controllo dei limiti della mappa
			continue;
		if (game->map_copy[current.x][current.y] == '1' || game->map_copy[current.x][current.y] == 'X') // Se è un muro o già visitata, salta
			continue;
		if (game->map_copy[current.x][current.y] == 'E' && target != 'E') // Se incontra un'uscita e il target non è l'uscita, la salta
			continue;
		if (game->map_copy[current.x][current.y] == 'C') // Se incontra un collectible, decrementa il contatore
			(*collectibles)--;		 
		game->map_copy[current.x][current.y] = 'X'; // Marca la cella come visitata
		i = 0; // Aggiungi le celle adiacenti alla coda
		while (i < 4)
		{
			enqueue(queue, (t_position){current.x + directions[i].x, current.y + directions[i].y});
			i++;
		}
	}
	free_queue(queue);
}

static int	ft_is_reachable(char **map, char c)
{
	int	i;

	i = 0;
	while (map[i])
	{
		int j = 0;
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

// Funzione principale di controllo
void	ft_pathfinding(t_game *game)
{
	t_position	start;
	int			collectibles;

	collectibles = game->tot_collectible;
	game->map_copy = ft_copy_map(game);
	if (!game->map_copy)
		ft_error_check(game, 4, "Error: Failed to copy map\n", 7);
	start = ft_find_position(game->map_copy, 'P');
	if (start.x == -1 || start.y == -1)
	{
		free_map_copy(game);
		ft_error_check(game, 4, "Error: Player position not found\n", 7);
	}
	ft_flood_fill(game, start, &collectibles, 'C');
	if (collectibles != 0) // Se rimangono collectible o l'uscita non è raggiungibile, errore
	{
		free_map_copy(game);
		ft_error_check(game, 4, "Error: Not all collectibles are reachable\n", 7);
	}
	free_map_copy(game);
	game->map_copy = ft_copy_map(game); // Ricopia la mappa per il controllo dell'uscita
	if (!game->map_copy)
		ft_error_check(game, 4, "Error: Failed to copy map for exit check\n", 7);
	ft_flood_fill(game, start, &collectibles, 'E'); // Verifica se l'uscita è raggiungibile dopo aver raccolto tutti i collectible
	if (!ft_is_reachable(game->map_copy, 'E'))
	{
		free_map_copy(game);
		ft_error_check(game, 4, "Error: Exit is not reachable\n", 7);
	}
	free_map_copy(game);
}
