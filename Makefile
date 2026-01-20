NAME        = push_swap
BONUS_NAME  = checker
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
DEBUGFLAG   = -g -D LOG_DEBUG=1
SRC_DIR     = src
LIBFT_DIR   = $(SRC_DIR)/libft
PRINTF_DIR  = $(SRC_DIR)/printf
CHECKER_DIR = bonus_src
LIBFT       = $(LIBFT_DIR)/libft.a
PRINTF      = $(PRINTF_DIR)/libftprintf.a
INCLUDES    = -I. -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(CHECKER_DIR)
SRCS        = algo_cost_calculation.c  LIS_optimization.c push_commands.c \
				reverse_rotate_commands.c swap_command.c algo_execution.c \
				LIS_utils.c min_sort.c rotate_commands.c t_stack_operations.c \
				algo_push_price_calculation.c init_stack.c main.c parsing.c
OBJS        = $(SRCS:.c=.o)
MAIN_FILE   = main.c
SHARED_OBJS = $(filter-out $(MAIN_FILE:.c=.o), $(OBJS))
BONUS_SRCS  =  $(CHECKER_DIR)/checker.c \
				$(CHECKER_DIR)/get_next_line.c \
				$(CHECKER_DIR)/get_next_line_utils.c \

BONUS_OBJS  = $(BONUS_SRCS:.c=.o)
ARGS_500    = $(shell shuf -i 1-1000 -n 500)
ARGS_100    = $(shell shuf -i 1-1000 -n 100)
ARGS_5      = $(shell shuf -i 1-1000 -n 5)
ARGS_3      = $(shell shuf -i 1-1000 -n 3)
CHEK_ARGS   :=$(shell shuf -i 1-1000 -n 500)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(SHARED_OBJS) $(BONUS_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SHARED_OBJS) $(BONUS_OBJS) $(LIBFT) $(PRINTF) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(CHECKER_DIR)/%.o: $(CHECKER_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean

re: fclean all

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

run_checker :
	./push_swap $(CHEK_ARGS) | ./checker_linux $(CHEK_ARGS)

.PHONY: all clean fclean re bonus run_500 run_100 run_5 run_3 leaks run_checker