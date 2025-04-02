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

// Strutture e prototipi per la coda
typedef struct s_node {
    t_position        pos;
    struct s_node    *next;
} t_node;

typedef struct s_queue {
    t_node    *front;
    t_node    *rear;
} t_queue;

t_queue		*create_queue(void);
void		enqueue(t_queue *queue, t_position pos);
t_position	dequeue(t_queue *queue);
int			is_empty(t_queue *queue);
void		free_queue(t_queue *queue);
void        free_map_copy(t_game *game);

// Crea una copia della mappa
static char **ft_copy_map(t_game *game)
{
    char **copy;
    int i;

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

// Trova la posizione di un carattere
static t_position ft_find_position(char **map, char c)
{
    t_position pos;
    int i;

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

static void ft_flood_fill(t_game *game, t_position start, int *collectibles)
{
    t_queue        *queue;
    t_position    directions[] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    t_position    current;
    int            i;

    queue = create_queue();
    enqueue(queue, start);
    while (!is_empty(queue))
    {
        current = dequeue(queue);
        if (current.x < 0 || current.y < 0 || current.x >= game->row || current.y >= game->col)
            continue;
        if (game->map_copy[current.x][current.y] == '1' || game->map_copy[current.x][current.y] == 'X')
            continue;
        if (game->map_copy[current.x][current.y] == 'C')
            (*collectibles)--;
        game->map_copy[current.x][current.y] = 'X';
        i = 0;
        while (i < 4)
        {
            enqueue(queue, (t_position){current.x + directions[i].x, current.y + directions[i].y});
            i++;
        }
    }
    free_queue(queue);
}

// Controlla se l'uscita è raggiungibile
static int ft_is_reachable(char **map, char c)
{
    int i;

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
void ft_check_valid_path(t_game *game)
{
    t_position start;
    int collectibles;

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
    ft_flood_fill(game, start, &collectibles);
    if (collectibles != 0 || !ft_is_reachable(game->map_copy, 'E'))
    {
        free_map_copy(game);
        ft_error_check(game, 4, "Error: Exit or collectibles unreachable\n", 7);
    }
    free_map_copy(game);
}

// Implementazioni delle funzioni della coda
t_queue *create_queue(void)
{
    t_queue *queue = malloc(sizeof(t_queue));
    if (!queue)
        return NULL;
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(t_queue *queue, t_position pos)
{
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
        return ;
    new_node->pos = pos;
    new_node->next = NULL;
    if (!queue->rear)
    {
        queue->front = new_node;
        queue->rear = new_node;
    }
    else
    {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

t_position dequeue(t_queue *queue)
{
    t_position pos = {-1, -1};
    if (!queue->front)
        return (pos);
    t_node *temp = queue->front;
    pos = temp->pos;
    queue->front = queue->front->next;
    if (!queue->front)
        queue->rear = (NULL);
    free(temp);
    return (pos);
}

int is_empty(t_queue *queue)
{
    return (queue->front == NULL);
}

void free_queue(t_queue *queue)
{
    while (!is_empty(queue))
        dequeue(queue);
    free(queue);
}
void free_map_copy(t_game *game)
{
    int i = 0;
    
    if (game && game->map_copy)
    {
        while (game->map_copy[i])
        {
            free(game->map_copy[i]);
            game->map_copy[i] = NULL;
            i++;
        }
        free(game->map_copy);
        game->map_copy = NULL;
    }
}
