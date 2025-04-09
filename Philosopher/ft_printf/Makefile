# Nome della libreria statica
NAME = ft_printf.a

# Compilatore e flag, -c compila i file .c e crea i file oggetto singolarmente
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Regola per compilare tutto
all: $(NAME)

# Lista dei file sorgenti e oggetti
SRCS = ft_printf.c ft_print_char.c ft_print_hexa.c ft_print_int.c ft_print_intunsign.c ft_print_pointer.c ft_print_str.c 

OBJS = $(SRCS:.c=.o)

# Regola per creare la libreria statica
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Libreria $(NAME) creata con successo!"

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
