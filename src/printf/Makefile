CC = cc 
CFLAGS = -Werror -Wextra -Wall 
NAME = libftprintf.a
SRC  = ft_print_numbers.c ft_print_strings.c ft_printf.c
OFILES = $(SRC:.c=.o)

all : $(NAME)

%.o : %c
	$(CC) -c $(CFLAGS) 	$< -o $@

$(NAME) : $(OFILES)
	ar  rcs  $(NAME) $(OFILES)
clean : 
	rm -f $(OFILES)

fclean: clean
		@rm -f $(NAME)
re: fclean all 

.PHONY: all bonus fclean clean 