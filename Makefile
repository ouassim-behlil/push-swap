NAME = push_swap

SRC =	base_stack_functions.c \
		custom_atoi.c \
		fill_stack.c \
		ft_split.c \
		main.c \
		stack_operations_1.c \
		stack_operations_2.c \
		push_swap.c \
		index_compression.c \
		push_swap_helper_1.c \
		push_swap_helper_2.c \
		push_swap_helper_3.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

HEADER = pushSwap.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
