NAME = 	push_swap
CC = 	gcc
FLAGS = -Wall -Wextra -Werror -g
SRC = 	push_swap.c push_argv.c pop_push.c argv_check.c ff_error.c argv_asd.c \
		moves_a.c moves_b.c rules.c\
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