NAME    = push_swap
SRC     = operations/swap.c\
		utils.c\
		atol_utils.c\
		lst_manage.c\
		operations/push.c\
		operations/rotate.c\
		operations/reverse_rot.c\
		sorting.c\
		greedy_sort.c\
		chunk_manager.c\
		node_manager.c\
		parsing.c\
		check_parsing.c\
		main.c

OBJ     = $(SRC:.c=.o)
CFLAGS  = -Wall -Wextra -Werror -ggdb
CC      = cc
LIBFT   = ./libft/libft.a
PRINTF  = ./printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF)
	@echo "COMPILATION DONE ! 👍"

$(LIBFT):
	@make -C ./libft > /dev/null 2>&1

$(PRINTF):
	@make -C ./printf > /dev/null 2>&1

%.o: %.c
	@$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make -C ./libft clean > /dev/null 2>&1
	@make -C ./printf clean > /dev/null 2>&1

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft fclean > /dev/null 2>&1
	@make -C ./printf fclean > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re