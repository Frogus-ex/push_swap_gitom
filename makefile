NAME    = push_swap
SRC     = swap.c\
		utils.c\
		lst_manage.c\
		push.c\
		rotate.c\
		reverse_rot.c\
		sorting.c\
		main.c

OBJ     = $(SRC:.c=.o)
CFLAGS  = -Wall -Wextra -Werror
CC      = cc
LIBFT   = ./libft/libft.a
PRINTF  = ./printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF)

$(LIBFT):
	make -C ./libft

$(PRINTF):
	make -C ./printf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C ./libft clean
	make -C ./printf clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean
	make -C ./printf fclean

re: fclean all

.PHONY: all clean fclean re