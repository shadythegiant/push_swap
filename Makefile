NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
SRCS        = main.c \
              init_stack.c \
              parsing.c \
              t_stack_operations.c

OBJS        = $(SRCS:.c=.o)
SRC_DIR     = src
LIBFT_DIR   = $(SRC_DIR)/libft
PRINTF_DIR  = $(SRC_DIR)/printf

LIBFT       = $(LIBFT_DIR)/libft.a
PRINTF      = $(PRINTF_DIR)/libftprintf.a
INCLUDES    = -I. -I$(LIBFT_DIR) -I$(PRINTF_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re