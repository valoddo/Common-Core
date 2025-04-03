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

t_queue	*create_queue(void)
{
	t_queue	*queue;

	queue = malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue->up = NULL;
	queue->down = NULL;
	return (queue);
}

void	enqueue(t_queue *queue, t_position pos)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->pos = pos;
	new_node->next = NULL;
	if (!queue->down)
	{
		queue->up = new_node;
		queue->down = new_node;
	}
	else
	{
		queue->down->next = new_node;
		queue->down = new_node;
	}
}

t_position	dequeue(t_queue *queue)
{
	t_position	pos;
	t_node		*temp;

	pos.x = -1;
	pos.y = -1;
	if (!queue->up)
		return (pos);
	temp = queue->up;
	pos = temp->pos;
	queue->up = queue->up->next;
	if (!queue->up)
		queue->down = (NULL);
	free (temp);
	return (pos);
}

void	free_queue(t_queue *queue)
{
	while (!(queue->up == NULL))
		dequeue (queue);
	free (queue);
}

void	free_map_copy(t_game *game)
{
	int	i;

	i = 0;
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
