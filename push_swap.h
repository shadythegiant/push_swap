#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "src/libft/libft.h"
# include "src/printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct stack_s
{
	int				value;
	int				current_position;
	int				push_price;
	bool			above_median;
	bool			cheapest;
	struct stack_s	*target_node;
	struct stack_s	*next;
	struct stack_s	*prev;
}					t_stack;

// initializing and parsing command line args:

// intitializing :
void				init_stack(t_stack **a, char **argv, bool split_argv);

// parsing :
int					ft_is_validinput(char *str);
void				ft_clean_stack(t_stack **stack);
void				ft_clean_argv(char **argv);
int					ft_find_duplicates(t_stack *a, int nbr);
int					ft_cleanup(t_stack **a, char **argv, bool argv_split);

// t_stack operations
t_stack				*ft_stacklast(t_stack *head);
void				ft_append_node(t_stack **stack, int nbr);
int					ft_stack_size(t_stack *stack);
t_stack				*ft_smallest_value(t_stack *node);
t_stack				*ft_cheapest_node(t_stack *node);
bool				is_sorted(t_stack *head);
t_stack				*find_max(t_stack *node);
void				sort_three(t_stack **head);
void				sort_five(t_stack **a, t_stack **b);

// algo
void				ft_set_position(t_stack *node);
void				ft_set_target_node(t_stack *a, t_stack *b);
void				ft_set_price(t_stack *a, t_stack *b);
void				ft_set_cheapest(t_stack *node);
void				ft_init_nodes(t_stack *a, t_stack *b);
void				ft_finish_stack_rotation(t_stack **node, t_stack *top_node,
						char stack_name);
void				ft_push_swap(t_stack **a, t_stack **b);

// commands

void				pa(t_stack **a, t_stack **b, bool print);
void				pb(t_stack **a, t_stack **b, bool print);
void				ra(t_stack **a, bool print);
void				rb(t_stack **b, bool print);
void				rr(t_stack **a, t_stack **b, bool print);
void				rra(t_stack **a, bool print);
void				rrb(t_stack **b, bool print);
void				rrr(t_stack **a, t_stack **b, bool print);
void				sa(t_stack **a, bool print);
void				sb(t_stack **b, bool print);
void				ss(t_stack **a, t_stack **b, bool print);
#endif