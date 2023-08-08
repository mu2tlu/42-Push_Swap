NAME = 	push_swap
CC = 	gcc
FLAGS = -Wall -Wextra -Werror -g
SRC = 	push_swap.c push_arg.c pop_and_push.c argument_check.c error.c ft_split_and_ft_atoll.c \
		printnode.c
OBJS = $(SRC:%.c=%.o)



LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) -o $(NAME) $(OBJS)  -L$(LIBFT_DIR) -lft

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(FLAGS) $(LIBFT_INC) -c $<

all: $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS)
fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
re: clean all
.PHONY = all fclean clean re