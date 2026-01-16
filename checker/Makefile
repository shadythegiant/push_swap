NAME = checker
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
ROOT_DIR = ..
SRC_DIR  = ../src
LIBFT    = $(SRC_DIR)/libft/libft.a
PRINTF   = $(SRC_DIR)/printf/libftprintf.a
INCLUDES = -I. -I$(ROOT_DIR) -I$(SRC_DIR)/libft -I$(SRC_DIR)/printf
SRC_CHECKER = checker.c get_next_line.c get_next_line_utils.c
OBJ_CHECKER = $(SRC_CHECKER:.c=.o)
SHARED_OBJS = $(ROOT_DIR)/push_commands.o \
              $(ROOT_DIR)/swap_command.o \
              $(ROOT_DIR)/rotate_commands.o \
              $(ROOT_DIR)/reverse_rotate_commands.o \
              $(ROOT_DIR)/t_stack_operations.o \
              $(ROOT_DIR)/init_stack.o \
              $(ROOT_DIR)/parsing.o \
			  $(ROOT_DIR)/algo_execution.o \
			  $(ROOT_DIR)/algo_cost_calculation.o \
			  $(ROOT_DIR)/LIS_optimization.o \
			  $(ROOT_DIR)/LIS_utils.o \
			  $(ROOT_DIR)/min_sort.o \
			  $(ROOT_DIR)/algo_push_price_calculation.o
all: $(NAME)

$(NAME): $(OBJ_CHECKER)
	@echo "Ensuring parent dependencies are built..."
	@make -C $(ROOT_DIR)
	@echo "Linking checker..."
	$(CC) $(CFLAGS) $(OBJ_CHECKER) $(SHARED_OBJS) $(LIBFT) $(PRINTF) -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ_CHECKER)
	# We do NOT clean parent dir here to keep them independent

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re