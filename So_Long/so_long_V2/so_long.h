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

#ifndef	SO_LONG_H
#define	SO_LONG_H

#include	<stdlib.h>
#include	<unistd.h>
#include	"minilibx-linux/mlx.h" 
#include	"libft/libft.h"
#include	"get_next_line/get_next_line.h"

# define	EMPTY	"assets/0_empty.xpm"
# define	WALL	"assets/1_wall.xpm"
# define	COLLECT	"assets/C_collectible.xpm"
# define	EXIT	"assets/E_exit.xpm"
# define	PLAYER	"assets/P_player.xpm"

//keysym
# define	KEY_ESC	65307
# define	KEY_A	97
# define	ARROW_LEFT	65361
# define	KEY_W	119
# define	ARROW_UP	65362
# define	KEY_D	100
# define	ARROW_RIGHT	65363
# define	KEY_S	115
# define	ARROW_DOWN	65364

# define SIZE 32;

typedef struct	s_game 
{
	void *mlx;// Puntatore alla connessione con la libreria MiniLibX
	void *win;// Puntatore alla finestra creata con MiniLibX
	char **map;// mappa del gioco
	int row;// righe della mappa
	int col;// colonne della mappa
	void *empty_img;// Immagine del terreno
	void *wall_img;// Immagine della parete
	void *collect_img;// Immagine del collectible
	void *exit_img;// Immagine dell'uscita
	void *player_img;// Immagine del giocatore
} t_game;

// Funzioni
int		ft_key_hook(int keycode, t_game *game);
int		ft_close_window(t_game *game);
void	ft_init_window(t_game *game);

char	**ft_parsing(int argc, char **argv, t_game *game);
void	ft_load_images(t_game *game);
void	ft_render_map(t_game *game);

void	ft_putstr(char *str);
size_t	ft_strlen(const char *a);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *s1, const char *s2);

char	**ft_fill_map(char **argv, t_game *game);
void	ft_map_check(t_game *game);
char	**process_line(t_game *game, char *text, char **temp);
char	**terminate_map_array(t_game *game);


void	ft_error_check(t_game *game, int free_level, char *msg, int exit_code);
void	ft_free_memory(t_game *game, int i);
void	free_map(t_game *game);
void	ft_error(char *str, int i);

#endif
