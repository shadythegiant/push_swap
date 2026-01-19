NAME        = push_swap
BONUS_NAME  = checker
CC          = cc
CFLAGS      = -Wall -Wextra -Werror  
DEBUGFLAG   = -g -D LOG_DEBUG=1
SRCS        = $(wildcard *.c)
OBJS        = $(SRCS:.c=.o)
ARGS_500    = $(shell shuf -i 1-1000 -n 500)
ARGS_100    = $(shell shuf -i 1-1000 -n 100)
ARGS_5      = $(shell shuf -i 1-1000 -n 5)
ARGS_3      = $(shell shuf -i 1-1000 -n 3)
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

run_500 :
	./push_swap $(ARGS_500) | wc -l 

run_100 :
	./push_swap $(ARGS_100) | wc -l

run_5 :
	./push_swap $(ARGS_5) | wc -l

run_3 :
	./push_swap $(ARGS_3) | wc -l
	 
leaks :
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --leak-resolution=high --num-callers=20 --errors-for-leak-kinds=all ./push_swap $(ARGS_500)

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

.PHONY: all clean fclean re bonus run_500 run_100 run_5 run_3 