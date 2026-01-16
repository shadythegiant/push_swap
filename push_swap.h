/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahidi <azahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:40:40 by azahidi           #+#    #+#             */
/*   Updated: 2026/01/12 16:40:43 by azahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "src/libft/libft.h"
# include "src/printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct stack_s
{
	int					value;
	int					current_position;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	bool				is_in_lis;
	n struct stack_s	*target_node;
	struct stack_s		*next;
	struct stack_s		*prev;
}						t_stack;

// initializing and parsing command line args:

// intitializing :
void					init_stack(t_stack **a, char **argv);

// parsing :
int						ft_is_validinput(char *str);
void					ft_clean_stack(t_stack **stack);
void					ft_clean_argv(char **argv);
int						ft_find_duplicates(t_stack *a, int nbr);
int						ft_cleanup(t_stack **a, char **argv, bool argv_split);

// t_stack operations
t_stack					*ft_stacklast(t_stack *head);
void					ft_append_node(t_stack **stack, int nbr);
int						ft_stack_size(t_stack *stack);
t_stack					*ft_smallest_value(t_stack *node);
t_stack					*ft_cheapest_node(t_stack *node);
bool					is_sorted(t_stack *head);
t_stack					*find_max(t_stack *node);
void					sort_three(t_stack **head);
void					sort_five(t_stack **a, t_stack **b);

// algo
void					ft_set_position(t_stack *node);
void					ft_set_target_node(t_stack *a, t_stack *b);
void					ft_set_price(t_stack *a, t_stack *b);
void					ft_set_cheapest(t_stack *node);
void					ft_init_nodes(t_stack *a, t_stack *b);
void					ft_finish_stack_rotation(t_stack **node,
							t_stack *top_node, char stack_name);
void					ft_push_swap(t_stack **a, t_stack **b);
void					ft_mark_lis(t_stack *a);
void					push_all_save_lis(t_stack **a, t_stack **b);
void					calculate_lis_indices(int *arr, int size,
							int **lis_flags);
int						*list_to_array(t_stack *stack, int size);
int						init_arrays(int size, int **len, int **sub_seq);
void					fill_lis_arrays(int *arr, int size, int *len,
							int *sub_seq);
void					mark_lis_path(int size, int *len, int *sub_seq,
							int **lis_flags);
void					ft_calculate_cost(t_stack *b, int len_a, int len_b);

// commands

void					pa(t_stack **a, t_stack **b, bool print);
void					pb(t_stack **a, t_stack **b, bool print);
void					ra(t_stack **a, bool print);
void					rb(t_stack **b, bool print);
void					rr(t_stack **a, t_stack **b, bool print);
void					rra(t_stack **a, bool print);
void					rrb(t_stack **b, bool print);
void					rrr(t_stack **a, t_stack **b, bool print);
void					sa(t_stack **a, bool print);
void					sb(t_stack **b, bool print);
void					ss(t_stack **a, t_stack **b, bool print);
#endif
