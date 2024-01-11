NAME=fdf
CFLAGS= -g -Wextra -Wall -Werror -I/usr/local/include
LIBFT= lib/libft/libft.a
MLX = -L./lib/minilibx-linux -lmlx -lXext -lX11 -lm
CC=cc

SRCS = main.c render.c handle_events.c parse_map.c free_stuff.c color.c
OBJS	:= ${SRCS:.c=.o}

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