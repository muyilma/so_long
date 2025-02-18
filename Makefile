NAME=so_long

SRCS=  get_next_line.c so_long.c map_control.c
CFLAGS=
LIBFT=libft/libft.a




$(NAME): $(SRCS) 
	make -C ./libft -s
	cc  -o $(NAME)  $(SRCS) $(LIBFT)  

all: $(NAME)

clean:
	make clean -C ./libft -s
	

fclean: clean
	make fclean -C ./libft -s
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re