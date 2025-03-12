# Nome della libreria
NAME = so_long

# Compilatore e flag, -c compila i file .c e crea i file oggetto singolarmente
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Regola per compilare tutto
all: $(NAME)

# Lista dei file sorgenti e oggetti
SRCS = input.c main.c map.c render.c so_long_utils.c

OBJS = $(SRCS:.c=.o)

# Regola per creare l'eseguibile di minilibx, libft e get_next_line
$(NAME): $(OBJS)
	make -C minilibx-linux
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) get_next_line/get_next_line.a libft/libft.a minilibx-linux/libmlx.a -Lminilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm
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
	@rm -f $(NAME)
	@echo "Pulizia completa (incluso $(NAME))!"

# Regola per ricompilare tutto
re: fclean all

# Evita errori nel caso i nomi delle regole coincidano con file reali
.PHONY: all clean fclean re

