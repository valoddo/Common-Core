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

// Aggiungi queste utility al tuo codice

typedef struct s_point {
    int x;
    int y;
} t_point;

// Funzione principale di controllo
void	ft_check_valid_path(t_game *game)
{
	char	**map_copy;
	int 	collectibles;

	map_copy = ft_copy_map(game); // Crea una copia modificabile della mappa
	collectibles = game->collectibles_count;
	t_point start = ft_find_position(map_copy, 'P'); // Trova la posizione iniziale del giocatore
	ft_flood_fill(map_copy, start, &collectibles); // Esegui il flood fill
	if (collectibles != 0) // Controlla risultati
		ft_error_check(game, 4, "Error: Unreachable collectibles\n", 7);
	if (!ft_is_reachable(map_copy, 'E'))
		ft_error_check(game, 4, "Error: Exit unreachable\n", 7);
	ft_free_map(map_copy); // Libera la mappa copia
}

// Helper function: Flood fill algorithm
static void	ft_flood_fill(char **map, t_point start, int *collectibles)
{
	Queue *queue = create_queue();
	enqueue(queue, start);
	t_point directions[] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // Direzioni: su, giù, sinistra, destra
	while (!is_empty(queue)) {
		t_point current = dequeue(queue);
		if (current.x < 0 || current.y < 0 || 
			current.x >= map_height || current.y >= map_width) // Controlla se usciamo dai bordi
			continue;
		char cell = map[current.x][current.y];
		if (cell == '1' || cell == 'X') // Controlla ostacoli e celle già visitate
			continue;
		if (cell == 'C') // Aggiorna collezionabili
			(*collectibles)--;
		map[current.x][current.y] = 'X'; // Marca come visitato
		for (int i = 0; i < 4; i++) // Aggiungi le direzioni alla coda
		{
			t_point new_point = 
			{
				current.x + directions[i].x;
				current.y + directions[i].y;
			}
			enqueue(queue, new_point);
		}
	}
	free_queue(queue);
}

// Crea una copia della mappa
char	**ft_copy_map(t_game *game)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * (game->row + 1));
	while (game->map[i])
	{
		copy[i] = strdup(game->map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

// Trova la posizione di un carattere
t_point	ft_find_position(char **map, char c)
{
    t_point pos = {-1, -1};
    int i = 0;
    
    while (map[i])
    {
        int j = 0;
        while (map[i][j])
        {
            if (map[i][j] == c) 
            {
                pos.x = i;
                pos.y = j;
                return pos;
            }
            j++;
        }
        i++;
    }
    return (pos);
}

// Controlla se l'uscita è raggiungibile
int ft_is_reachable(char **map, char c)
{
    int i 

    i = 0;
    while (map[i])
    {
        int j = 0;
        while (map[i][j])
        {
            if (map[i][j] == c)
                return (0); // Trovato carattere non raggiunto
            j++;
        }
        i++;
    }
    return (1);
}
