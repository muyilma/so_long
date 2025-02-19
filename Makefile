NAME=so_long

SRCS=  libft/get_next_line.c so_long.c map_control.c map_control2.c
CFLAGS=-g
LIBFT=libft/libft.a

$(NAME): $(SRCS) 
	make -C ./libft -s
	cc  -o  $(NAME) -g $(SRCS) $(LIBFT)  

all: $(NAME)

clean:
	make clean -C ./libft -s
	

fclean: clean
	make fclean -C ./libft -s
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re