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

int ft_key_hook(int keycode, t_game *game) 
{    
    if (keycode == KEY_ESC)
        close_window(game);
    // else if (keycode == KEY_D || keycode == ARROW_RIGHT)
	// 	movement(0, 1, game);
	// else if (keycode == KEY_A || keycode == ARROW_LEFT)
	// 	movement(0, -1, game);
	// else if (keycode == KEY_W || keycode == ARROW_UP)
	// 	movement(-1, 0, game);
	// else if (keycode== KEY_S || keycode == ARROW_DOWN)
	// 	movement(1, 0, game);
    return (0);
}

int ft_close_window(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win);  // Chiudi la finestra
    exit(0); // Termina il programma
}

void    init_window(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        ft_putstr("Error: Impossible initialize MiniLibX\n");
        exit(1);
    }
    game->win = mlx_new_window(game->mlx, 800, 200, "so_long");
    if (!game->win)
    {
        ft_putstr("Error: Impossible create the window\n");
        exit(1);
    }
    ft_load_images(game);  // Carica le immagini
    ft_render_map(game);   // Renderizza la mappa
    // // Imposta i gestori per gli eventi
    mlx_hook(game->win, 2, 1L << 0, ft_key_hook, game);  // Gestisci tasti (KeyPress)
    mlx_hook(game->win, 17, 1L << 17, ft_close_window, game);  // Gestisci chiusura finestra (DestroyNotify)
}

int main(int argc, char **argv)
{
    t_game *game;

    game = (t_game *) {0};
    game  = malloc(sizeof(t_game));
    if (!game)
        return(1);
    game->map = ft_parsing(argc, argv, game);
    ft_init_window(&game);
    mlx_loop(game->mlx); // Aspetta eventi e mantiene la finestra aperta
    return (0);

}