NAME=so_long

SRCS=  libft/get_next_line.c so_long.c map_control.c map_control2.c mlx.c
CFLAGS=-g
LIBFT=libft/libft.a
MLX_LIB=minilibx/libmlx.a

MLX_FLAGS=-L minilibx -lmlx -L/usr/X11R6/lib -lXext -lX11 -lm -lbsd

$(NAME): $(SRCS) 
	make -C ./libft -s
	make -C ./minilibx -s
	cc  -o  $(NAME) -g $(SRCS) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS)

all: $(NAME)

clean:
	make clean -C ./libft -s
	

fclean: clean
	make fclean -C ./libft -s
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re