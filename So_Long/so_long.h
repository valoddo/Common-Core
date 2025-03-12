/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:59:34 by vloddo            #+#    #+#             */
/*   Updated: 2025/03/11 13:59:36 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include    <stdlib.h>
#include    <unistd.h>
#include    "minilibx-linux/mlx.h" 
#include    "libft/libft.h"
#include    "get_next_line/get_next_line.h"

# define    EMPTY "assets/0_empty.xpm"
# define    WALL "assets/1_wall.xpm"
# define    COLLECT "assets/C_collectible.xpm"
# define    EXIT "assets/E_exit.xpm"
# define    PLAYER "assets/P_player.xpm"

//keysym
# define KEY_ESC 65307
# define KEY_A 97
# define ARROW_LEFT 65361
# define KEY_W 119
# define ARROW_UP 65362
# define KEY_D 100
# define ARROW_RIGHT 65363
# define KEY_S 115
# define ARROW_DOWN 65364

# define SIZE 50;

typedef struct  s_game {
    void *mlx;        // Puntatore alla connessione con la libreria MiniLibX
    void *win;        // Puntatore alla finestra creata con MiniLibX
    char **map;       // mappa del gioco
    int row;         // righe della mappa
    int column;     // colonne della mappa
    void *empty_img;   // Immagine del terreno
    void *wall_img;    // Immagine della parete
    void *collect_img; // Immagine del collectible
    void *exit_img;    // Immagine dell'uscita
    void *player_img;  // Immagine del giocatore
} t_game;

// Funzioni
char    **read_map(const char *filename);
void    ft_render_map(t_game *game);
void    ft_load_images(t_game *game);
// int     move_player(int keycode, t_game *game);
void    ft_putstr(char *str);
int     ft_close_window(t_game *game);

#endif
