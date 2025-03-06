NAME = push_swap
SOURCES = \
	push_swap.c list_utils.c push.c reverse_rotate.c rotate.c swap.c check.c \
	algo.c set_data.c algo_utils.c

OBJDIR = obj
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = my_libft/mylibft.a

MY_LIBFT_DIR = my_libft
MY_LIBFT = $(MY_LIBFT_DIR)/mylibft.a

$(MY_LIBFT):
	$(MAKE) -C $(MY_LIBFT_DIR)

all: $(MY_LIBFT) $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(MY_LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MY_LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re