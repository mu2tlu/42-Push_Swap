NAME = 	push_swap
B_NAME = checker
CC = 	gcc
FLAGS = -Wall -Wextra -Werror
SRC = 	push_swap.c pop_push_argv.c argv_check.c ff_error.c argv.c \
		moves.c moves_a.c moves_b.c sort_1.c sort_2.c sort_3.c \

BONUS = checker.c pop_push_argv.c argv_check.c ff_error.c argv.c \
		moves.c moves_a.c moves_b.c sort_1.c sort_2.c sort_3.c \
		
OBJS = $(SRC:%.c=%.o)
B_OBJS = $(BONUS:%.c=%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) -o $(NAME) $(OBJS)  -L$(LIBFT_DIR) -lft

$(B_NAME): $(B_OBJS) $(LIBFT)
	@$(CC) -o $(B_NAME) $(B_OBJS)  -L$(LIBFT_DIR) -lft

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(FLAGS) $(LIBFT_INC) -c $<

all: $(NAME)

bonus: $(B_NAME) 

clean:
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS) $(B_OBJS)
fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME) $(B_NAME)
re: clean all
.PHONY = all fclean clean re bonus