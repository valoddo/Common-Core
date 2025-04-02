/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:58:57 by vloddo            #+#    #+#             */
/*   Updated: 2025/03/11 13:58:58 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, t_game *game)
{    
	if (keycode == KEY_ESC)
		ft_close_window(game);
	else if (keycode == KEY_D || keycode == ARROW_RIGHT)
		ft_movement(game, 0, 1);
	else if (keycode == KEY_A || keycode == ARROW_LEFT)
		ft_movement(game, 0, -1);
	else if (keycode == KEY_W || keycode == ARROW_UP)
	 	ft_movement(game, -1, 0);
	else if (keycode== KEY_S || keycode == ARROW_DOWN)
	 	ft_movement(game, 1, 0);
	return (0);
}


void ft_movement(t_game *game, int delta_x, int delta_y)
{
	int new_x;
	int new_y;
	char target_tile;

	new_x = game->player_x + delta_x;
	new_y = game->player_y + delta_y;
	if (new_x < 0 || new_y < 0 || new_x >= game->row || new_y >= game->col) // Controllo dei bordi della mappa
        return ;
    target_tile = game->map[new_x][new_y];
	if (target_tile == '1') // Controllo muri
        return ;
	if (target_tile == 'E') // Controllo uscita
	{
		if (game->tot_collectible == 0)
			ft_close_window(game);
		return ;
	}
	if (target_tile == 'C') // Gestione collezionabili
	{
		game->tot_collectible--;
		game->map[new_x][new_y] = '0';
	}
	mlx_put_image_to_window(game->mlx, game->win, game->empty_img, 
							game->player_y * 32, game->player_x * 32); // Aggiornamento grafico
    game->player_x = new_x; // Aggiornamento posizione giocatore
    game->player_y = new_y;
	mlx_put_image_to_window(game->mlx, game->win, game->player_img,
							new_y * 32, new_x * 32); // Disegna nuovo giocatore
	game->moves++; // (Opzionale) Aggiorna contatore mosse
	ft_printf("Moves: %d\n", game->moves);
}

int	ft_close_window(t_game *game)
{
	mlx_destroy_image(game->mlx, game->empty_img);
	mlx_destroy_image(game->mlx, game->wall_img);
	mlx_destroy_image(game->mlx, game->collect_img);
	mlx_destroy_image(game->mlx, game->exit_img);
	mlx_destroy_image(game->mlx, game->exit_1_img);
	mlx_destroy_image(game->mlx, game->player_img);
	mlx_destroy_image(game->mlx, game->player_1_img);
	mlx_destroy_image(game->mlx, game->player_back_img);
	mlx_destroy_image(game->mlx, game->player_back_1_img);
	mlx_destroy_image(game->mlx, game->player_lside_img);
	mlx_destroy_image(game->mlx, game->player_lside_1_img);
	mlx_destroy_image(game->mlx, game->player_rside_img);
	mlx_destroy_image(game->mlx, game->player_rside_1_img);
	mlx_destroy_window(game->mlx, game->win); // Chiudi la finestra
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free_memory(game, 4);
	exit(0); // Termina il programma
}
