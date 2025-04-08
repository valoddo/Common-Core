/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:58:48 by vloddo            #+#    #+#             */
/*   Updated: 2025/03/11 13:58:50 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_check(t_game *game, int level, char *msg, int exit_code)
{
	ft_putstr(msg);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free_memory(game, level);
	exit(exit_code);
}

void	ft_free_memory(t_game *game, int i)
{
	while (i <= 5)
	{
		if (i == 5)
			free(game);
		else if (i == 4)
			free_map(game);
		i++;
	}
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game && game->map)
	{
		while (i < game->row)
		{
			free(game->map[i]);
			game->map[i] = NULL;
			i++;
		}
		free(game->map);
		game->map = NULL;
		game->row = 0;
	}
}

void	*ft_calloc(size_t num, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = num * size;
	if (num != 0 && total_size / num != size)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = s;
	while (i < n)
	{
		p[i] = (unsigned char )c;
		i++;
	}
	return (s);
}
