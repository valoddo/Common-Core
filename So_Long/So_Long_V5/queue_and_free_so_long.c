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
	t_queue	*queue = malloc(sizeof(t_queue));
	if (!queue)
		return NULL;
	queue->front = NULL;
	queue->rear = NULL;
	return (queue);
}

void	enqueue(t_queue *queue, t_position pos)
{
	t_node *new_node;

	new_node = malloc(sizeof(t_node));
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

t_position	dequeue(t_queue *queue)
{
	t_position pos = {-1, -1};
	if (!queue->front)
		return (pos);
	t_node *temp = queue->front;
	pos = temp->pos;
	queue->front = queue->front->next;
	if (!queue->front)
		queue->rear = (NULL);
	free (temp);
	return (pos);
}

void	free_queue(t_queue *queue)
{
	while (!(queue->front == NULL))
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

