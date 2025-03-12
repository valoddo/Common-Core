/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:19:41 by vloddo            #+#    #+#             */
/*   Updated: 2025/03/12 16:19:42 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

// void	free_map(t_game *data)
// {
// 	if (data && data->map)
// 	{
// 		if (data->map->map_matrix)
// 			free_matrix(data->map->map_matrix, data->map->rows);
// 		free(data->map);
// 		data->map = NULL;
// 	}
// }

// void	error_msg(char *msg, t_game data)
// {
// 	ft_putstr("Error\n");
// 	ft_printf("%s\n", msg);
// 	free_map(&data);
// 	exit(1);
// }
