NAME        = push_swap
BONUS_NAME  = checker
CC          = cc
CFLAGS      = -Wall -Wextra -Werror  
DEBUGFLAG   = -g -D LOG_DEBUG=1

# Source files in the root directory
SRCS        = $(wildcard *.c)
OBJS        = $(SRCS:.c=.o)

# Directories
SRC_DIR     = src
LIBFT_DIR   = $(SRC_DIR)/libft
PRINTF_DIR  = $(SRC_DIR)/printf
CHECKER_DIR = checker

# Libraries
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

# Fixed the typo here: CHEKCER -> CHECKER
bonus:
	@make -C $(CHECKER_DIR)

clean:
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean
	@make -C $(CHECKER_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	@make -C $(CHECKER_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus