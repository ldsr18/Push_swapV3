NAME = push_swap

LIBFT_PATH = Libft/
LIBFT = $(LIBFT_PATH)libft.a

SRCS = 	error_handling.c \
		init_a_to_b.c \
		init_b_to_a.c \
		push_swap.c \
		push.c \
		rev_rotate.c \
		rotate.c \
		sort_stacks_utils.c \
		sort_stacks.c \
		sort_three.c \
		init_node.c \
		stack_init.c \
		stack_utils.c \
		swap.c

OBJS = ${SRCS:.c=.o}

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_PATH)

.c.o:
	${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}

$(LIBFT):
	make -C ${LIBFT_PATH}

all: ${NAME}

clean: 
	${RM} ${OBJS}
	make clean -C ${LIBFT_PATH}

fclean: clean
	${RM} ${NAME}
	make fclean -C ${LIBFT_PATH}

re: fclean all

.PHONY: all clean fclean re