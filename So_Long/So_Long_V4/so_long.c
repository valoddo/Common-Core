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

void    ft_init_window(t_game *game)
{
    int  width;// 32 è la dimensione di un tile
    int height;

    width = game->col * 32;
    height = game->row * 32;
    game->win = mlx_new_window(game->mlx, width, height, "so_long");
    if (!game->win)
        ft_error_check(game, 4, "Error: Impossible to create the window\n", 10);
    ft_load_images(game);  // Carica le immagini
    ft_render_map(game);   // Renderizza la mappa
    // // Imposta i gestori per gli eventi
    mlx_hook(game->win, 2, 1L << 0, ft_key_hook, game);  // Gestisci tasti (KeyPress)
    mlx_hook(game->win, 17, 1L << 17, ft_close_window, game);  // Gestisci chiusura finestra (DestroyNotify)
}

int ft_key_hook(int keycode, t_game *game)
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
    int new_x = game->player_x + delta_x;
    int new_y = game->player_y + delta_y;

    // Controllo dei bordi della mappa
    if (new_x < 0 || new_y < 0 || new_x >= game->row || new_y >= game->col)
        return;

    char target_tile = game->map[new_x][new_y];

    // Controllo muri
    if (target_tile == '1')
        return;

    // Controllo uscita
    if (target_tile == 'E') {
        if (game->tot_collectible == 0)
            ft_close_window(game);
        return;
    }

    // Gestione collezionabili
    if (target_tile == 'C') {
        game->tot_collectible--;
        game->map[new_x][new_y] = '0';
    }

    // Aggiornamento grafico
    mlx_put_image_to_window(game->mlx, game->win, game->empty_img, 
                          game->player_y * 32, game->player_x * 32);
    
    // Aggiornamento posizione giocatore
    game->player_x = new_x;
    game->player_y = new_y;
    
    // Disegna nuovo giocatore
    mlx_put_image_to_window(game->mlx, game->win, game->player_img,
                          new_y * 32, new_x * 32);

    // (Opzionale) Aggiorna contatore mosse
    game->moves++;
    printf("Moves: %d\n", game->moves);
}

int ft_close_window(t_game *game)
{
    mlx_destroy_image(game->mlx, game->empty_img);
    mlx_destroy_image(game->mlx, game->wall_img);
    mlx_destroy_image(game->mlx, game->collect_img);
    mlx_destroy_image(game->mlx, game->exit_img);
    mlx_destroy_image(game->mlx, game->exit_1_img);
    mlx_destroy_image(game->mlx, game->player_img);
    mlx_destroy_image(game->mlx, game->player_1_img);
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



int main(int argc, char **argv)
{
    t_game *game;

    game = ft_calloc(1, sizeof(t_game));
    if (!game)
        return (1);
    game->mlx = mlx_init(); // Inizializza la connessione MLX (FONDAMENTALE) 
    if (!game->mlx)
    {
        free(game);
        ft_putstr("Error: MLX initialization failed\n");
        return (1);
    }
    game->map = ft_parsing(argc, argv, game);
    ft_init_window(game);
    mlx_loop(game->mlx);
    return (0);
}
