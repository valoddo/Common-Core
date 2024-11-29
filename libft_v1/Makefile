# Nome della libreria statica
NAME = libft.a

# Compilatore e flag, -c compila i file .c e crea i file oggetto singolarmente
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Regola per compilare tutto
all: $(NAME)

# Lista dei file sorgenti e oggetti
SRCS = ft_memcpy.c ft_memset.c ft_strlen.c ft_isdigit.c ft_isalnum.c ft_memset.o ft_bzero.c ft_isprint.c ft_isascii.c ft_isalpha.c ft_memmove.c ft_atoi.c ft_toupper.c ft_tolower.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c

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
