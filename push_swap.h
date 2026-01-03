#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "src/libft/libft.h"
#include "src/printf/ft_printf.h"

typedef struct stack_s {
	int				value; 
	int				current_position;  
	int				push_price; 
	bool			above_median; 
	bool			cheapest; 
	struct stack_s	*target_node; 
	struct stack_s 	*next; 
	struct stack_s	*prev; 
}					t_stack; 



// initializing and parsing command line args: 

// intitializing : 
void init_stack(t_stack **a, char **argv, bool split_argv); 


// parsing : 
int ft_is_validinput(char *str); 
void ft_clean_stack(t_stack **stack); 
void ft_clean_argv(char **argv); 
int ft_find_duplicates(t_stack *a, int nbr); 
int ft_cleanup(t_stack **a, char **argv, bool argv_split); 


// t_stack operations 
t_stack *ft_stacklast(t_stack *head); 
void ft_append_node(t_stack **stack , int nbr); 
int ft_stack_size(t_stack *stack);
t_stack *ft_smallest_value(t_stack *node);
t_stack *ft_cheapest_node(t_stack *node);
bool is_sorted(t_stack *head); 









#endif