NAME=fdf
CFLAGS= -g -Wextra -Wall -Werror -I/usr/local/includes -I./includes
LIBFT= lib/libft/libft.a
MLX = -L./lib/minilibx-linux -lmlx -lXext -lX11 -lm
CC=cc

SRCDIR = src includes
SOURCES := $(shell find $(SRCDIR) -name '*.c')
OBJS := ${SOURCES:.c=.o}

RM=rm -rf

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	@$(CC) $(OBJS) $(MLX) $(LIBFT) -o $(NAME)

$(MLX) :
	$(MAKE) -C ./lib/minilibx-linux

$(LIBFT) :
	$(MAKE) -C ./lib/libft

all: $(NAME)

clean:
		$(MAKE) clean -C ./lib/libft
		$(RM) $(OBJS)

fclean: clean
		$(MAKE) fclean -C ./lib/libft
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re