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
#include	"get_next_line/get_next_line.h"

# define	EMPTY	"assets/0_empty.xpm"
# define	WALL	"assets/1_wall.xpm"
# define	COLLECT	"assets/C_collectible.xpm"
# define	EXIT	"assets/E_exit.xpm"
# define	EXIT_1	"assets/E_exit_1.xpm"
# define	PLAYER	"assets/P_player.xpm"
# define	PLAYER_1	"assets/P_player_1.xpm"
# define	PLAYER_BACK	"assets/P_player_back.xpm"
# define	PLAYER_RSIDE	"assets/P_player_rside.xpm"
# define	PLAYER_LSIDE	"assets/P_player_lside.xpm"
# define	PLAYER_RSIDE_1	"assets/P_player_rside_1.xpm"
# define	PLAYER_LSIDE_1	"assets/P_player_lside_1.xpm"

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

# define SIZE 32

typedef struct	s_game 
{
	void *mlx;// Puntatore alla connessione con la libreria MiniLibX
	void *win;// Puntatore alla finestra creata con MiniLibX
	char **map;// mappa del gioco
	char **map_copy;// copia della mappa del gioco
	int row;// righe della mappa
	int col;// colonne della mappa
	int	tot_collectible; //totale collectable
	int player_x; // posizione x player
	int player_y; // posizione y player
	int	moves; // conto dei movimenti
	void *empty_img;// Immagine del terreno
	void *wall_img;// Immagine della parete
	void *collect_img;// Immagine del collectible
	void *exit_img;// Immagine dell'uscita
	void *exit_1_img;// Immagine dell'uscita
	void *player_img;// Immagine del 
	void *player_1_img;// Immagine del giocatore camminata
	void *player_back_img;// Immagine del giocatore di spalle
	void *player_rside_img;// Immagine del giocatore destra
	void *player_rside_1_img;// Immagine del giocatore destra camminata
	void *player_lside_img;// Immagine del giocatore sinistra
	void *player_lside_1_img;// Immagine del giocatore sinistra camminata
} t_game;

typedef struct	s_position
{
	int	x; //coordinata
	int	y; //coordinata
}	t_position;

// so_long.c
void	ft_init_window(t_game *game);
int		ft_key_hook(int keycode, t_game *game);
void	ft_movement(t_game *game, int delta_x, int delta_y);
int		ft_close_window(t_game *game);

// so_long_map.c
char	**ft_parsing(int argc, char **argv, t_game *game);
char	**ft_fill_map(char **argv, t_game *game);
int		read_and_process_lines(t_game *game, int fd);
char	**process_line(t_game *game, char *text, char **temp);
char	**terminate_map_array(t_game *game);
void	ft_load_images(t_game *game);
void	ft_render_map(t_game *game);

// so_long_map_checks.c
void	ft_map_check_frame(t_game *game);
void	ft_map_check_player(t_game *game);
void	ft_map_check_exit(t_game *game);
void	ft_map_check_collectible(t_game *game);
void	ft_map_check_field(t_game *game);

// so_long.utils.c
size_t	ft_strlen(const char *a);
void	ft_putstr(char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *s1, const char *s2);
void	*ft_calloc(size_t num, size_t size);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strdup(const char *s);

// error_free_so_long.c
void	ft_error_check(t_game *game, int free_level, char *msg, int exit_code);
void	ft_free_memory(t_game *game, int i);
void	free_map(t_game *game);
//void	ft_error(char *str, int i);

// pathfinding.c
void ft_check_valid_path(t_game *game);


#endif
