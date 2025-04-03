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
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h" 
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"

# define EMPTY	"assets/0_empty.xpm"
# define WALL	"assets/1_wall.xpm"
# define COLLECT	"assets/C_collectible.xpm"
# define EXIT	"assets/E_exit.xpm"
# define PLAY	"assets/P_player.xpm"

//keysym
# define KEY_ESC	65307
# define KEY_A	97
# define ARROW_LEFT	65361
# define KEY_W	119
# define ARROW_UP	65362
# define KEY_D	100
# define ARROW_RIGHT	65363
# define KEY_S	115
# define ARROW_DOWN	65364

# define SIZE 32

typedef struct s_game
{
	void	*mlx;// Puntatore alla connessione con la libreria MiniLibX
	void	*win;// Puntatore alla finestra creata con MiniLibX
	char	**map;// mappa del gioco
	char	**map_copy;// copia della mappa del gioco
	int		row;// righe della mappa
	int		col;// colonne della mappa
	int		tot_collectible; //totale collectable
	int		play_x; // posizione x player
	int		play_y; // posizione y player
	int		moves; // conto dei movimenti
	void	*empty;// Immagine del terreno
	void	*wall;// Immagine della parete
	void	*collect;// Immagine del collectible
	void	*exit;// Immagine dell'uscita
	void	*play;// Immagine del giocatore
}	t_game;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_node
{
	t_position		pos;
	struct s_node	*next;
}	t_node;

typedef struct s_queue
{
	t_node	*up;
	t_node	*down;
}	t_queue;

// so_long.c
char		**ft_parsing(int argc, char **argv, t_game *game);
void		ft_init_window(t_game *game);
void		ft_load_images(t_game *game);
void		ft_render_map(t_game *game);

// map_so_long.c
int			ft_is_empty_file(int fd);
char		**ft_fill_map(char **argv, t_game *game);
int			read_and_process_lines(t_game *game, int fd);
char		**process_line(t_game *game, char *text, char **temp);
char		**terminate_map_array(t_game *game);

// map_checks_so_long.c
void		ft_map_check_frame(t_game *game);
void		ft_map_check_player(t_game *game);
void		ft_map_check_exit(t_game *game);
void		ft_map_check_collectible(t_game *game);
void		ft_map_check_field(t_game *game);

// pathfinding_utils_so_long.c
char		**ft_copy_map(t_game *game);
t_position	ft_find_position(char **map, char c);
void		ft_flood_fill(t_game *game, t_position start, int *c, char target);
void		ft_flood_fill_loop(t_game *game, t_queue *queue, \
			int *c, char target);
int			ft_is_reachable(char **map, char c);

// pathfinding_so_long.c
void		ft_pathfinding_p(t_game *game);
void		ft_pathfinding_e(t_game *game);

// queue_and_free_so_long.c
t_queue		*create_queue(void);
void		enqueue(t_queue *queue, t_position pos);
t_position	dequeue(t_queue *queue);
void		free_queue(t_queue *queue);
void		free_map_copy(t_game *game);

// movement_close_so_long.c
int			ft_key_hook(int keycode, t_game *game);
void		ft_movement(t_game *game, int x, int y);
void		ft_count_move(t_game *game, int new_x, int new_y);
int			ft_close_window(t_game *game);

// so_long.utils.c
size_t		ft_strlen(const char *a);
void		ft_putstr(char *str);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *s1, const char *s2);
char		*ft_strdup(const char *s);

// error_free_so_long.c
void		ft_error_check(t_game *game, int level, char *msg, int exit_code);
void		ft_free_memory(t_game *game, int i);
void		free_map(t_game *game);
void		*ft_calloc(size_t num, size_t size);
void		*ft_memset(void *s, int c, size_t n);

#endif
