# Nome della libreria
NAME = philo

# Compilatore e flag, -c compila i file .c e crea i file oggetto singolarmente
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Regola per compilare tutto
all: $(NAME)

# Lista dei file sorgenti e oggetti
SRCS = 

OBJS = $(SRCS:.c=.o)

# Regola per creare l'eseguibile di minilibx, libft e get_next_line
$(NAME): $(OBJS)
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) ft_printf/ft_printf.a
	@echo "Eseguibile $(NAME) creato con successo!"

# Regola per compilare i file .o dai file .c
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Regola per pulire i file oggetto
clean:
	make -C ft_printf fclean
	@rm -f $(OBJS) 
	@echo "Pulizia file oggetto completata!"

# Regola per pulire tutto (file oggetto + libreria)
fclean: clean
	make -C ft_printf fclean
	@rm -f $(NAME)
	@echo "Pulizia completa (incluso $(NAME))!"

# Regola per ricompilare tutto
re: fclean all

# Evita errori nel caso i nomi delle regole coincidano con file reali
.PHONY: all clean fclean re

