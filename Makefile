NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = push_swap.c push.c printnode.c
OBJ = $(SRC:%.c=%.o)



LIBFT_DIR = include/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) -o $(NAME) $(OBJ)  -L$(LIBFT_DIR) -lft

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(FLAGS) $(LIBFT_INC) -c $<

all: $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ)
fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
re: clean all
.PHONY = all fclean clean re