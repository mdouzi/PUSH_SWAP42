NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = src/algo.c src/rules_2.c src/stack.c src/check.c src/parsing.c src/push_help.c src/push_swap.c src/rules.c src/sort.c 
OBJS = $(SRCS:.c=.o)
RM = rm -f
LIBFT = inc/libft/libft.a

$(NAME): $(OBJS)
	@make -C inc/libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c inc/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@make -C inc/libft clean
	$(RM) $(OBJS)

fclean: clean
	@make -C inc/libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re