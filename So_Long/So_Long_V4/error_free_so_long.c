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

void	ft_error_check(t_game *game, int free_level, char *msg, int exit_code)
{
	ft_putstr(msg);
    mlx_destroy_display(game->mlx); // Deve essere chiamato prima del free
    free(game->mlx);
	ft_free_memory(game, free_level);
	exit(exit_code);
}

void	ft_free_memory(t_game *game, int i)
{
	while (i <= 5)
	{
		if ( i == 5)
        {
			free(game);
        }
		else if ( i == 4)
			free_map(game);
		i++;
	}
}
void free_map(t_game *game)
{
    int i = 0;
    
    if (game && game->map)
    {
        while (i < game->row)
        {
            free(game->map[i]);
            game->map[i] = NULL; // Buona pratica
            i++;
        }
        free(game->map);
        game->map = NULL;
        game->row = 0;    // Resetta il contatore
    }
}

// void ft_free_memory(t_game *game, int i)
// {
//     if (i >= 4) // Gestione errori in ordine inverso all'allocazione
//     {
//         if (game && game->map) // Libera la mappa solo se esiste
//         {
//             free_map(game);
//             game->map = NULL; // Previene doppi free
//         }
//     }
//     if (i >= 5)
//     {
//         if (game && game->win) // Distrugge la finestra solo se esiste
//         {
//             mlx_destroy_window(game->mlx, game->win);
//             game->win = NULL;
//         }
//         if (game && game->mlx) // Gestione corretta di MLX per Linux
//         {
//             mlx_destroy_display(game->mlx); // Deve essere chiamato prima del free
//             free(game->mlx);
//             game->mlx = NULL;
//         }
//         if (game) // Libera la struttura game solo se allocata dinamicamente
//             free(game);
//     }
// }


// void	free_map(t_game *game)
// {
// 	int	i;
	
// 	i = 0;
// 	if (game && game->map)
// 	{
// 		while (i < game->row)
// 		{
// 			free(game->map[i]);
// 			i++;
// 		}
// 		free(game->map);
// 	}
// }


// void	ft_error(char *str, int i)
// {
// 	if (i == 5) // errore in ft_parsing se gli argomenti non sono corretti 
// 		write(1, "Usage: ./game <map.ber>\n", 25);
// 	else if (i == 6) //errore in ft_fill_map
// 		write(1, "Error: No such file or directory\n", 34);
// 	else if (i == 7) //errore in ft_fill_map
// 		write(1, "Error: insert valid map\n", 25);
// 	else if (i == 8) // errore in ft_map_check per mappa non rettangolare
// 		write(1, "Error: insert valid rectangular map\n", 37);
// 	else if (i == 9) // errore in ft_load_images
// 		write(1, "Error: Failed to load images\n", 29);
// 	else if (i == 10) // errore in ft_init_window se non viene creata la finestra
// 		write(1, "Error: Impossible to create the window\n", 37);
// 	{
// 		perror(str);
// 		exit(i);
// 	}
// 	exit(i);
// }
