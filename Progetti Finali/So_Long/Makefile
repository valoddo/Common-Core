# Nome della libreria
NAME = so_long

# Compilatore e flag, -c compila i file .c e crea i file oggetto singolarmente
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAG = -lmlx -lXext -lX11

# Regola per compilare tutto
all: $(NAME)

# Lista dei file sorgenti e oggetti
SRCS = main_so_long.c so_long.c map_so_long.c utils_so_long.c map_checks_so_long.c error_free_so_long.c pathfinding_so_long.c pathfinding_utils_so_long.c queue_and_free_so_long.c movement_close_so_long.c itoa_so_long.c sprite_so_long.c

OBJS = $(SRCS:.c=.o)

# Regola per creare l'eseguibile di minilibx, libft e get_next_line
$(NAME): $(OBJS)
	make -C minilibx-linux
	make -C get_next_line
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) ft_printf/ft_printf.a get_next_line/get_next_line.a minilibx-linux/libmlx.a -Lminilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm
	@echo "Eseguibile $(NAME) creato con successo!"

# Regola per compilare i file .o dai file .c
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Regola per pulire i file oggetto
clean:
	@rm -f $(OBJS) 
	@echo "Pulizia file oggetto completata!"

# Regola per pulire tutto (file oggetto + libreria)
fclean: clean
	make -C get_next_line fclean
	make -C ft_printf fclean
	@rm -f $(NAME)
	@echo "Pulizia completa (incluso $(NAME))!"

# Regola per ricompilare tutto
re: fclean all

# Evita errori nel caso i nomi delle regole coincidano con file reali
.PHONY: all clean fclean re

