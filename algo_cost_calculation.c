#include "push_swap.h"

void	set_position(t_stack *node)
{
	int	i;
	int	median_line;

	if (node == NULL)
		return ;
	i = 0;
	median_line = ft_stack_size(node) / 2;
	while (node)
	{
		node->current_position = i;
		if (node->current_position <= median_line)
			node->above_median = true;
		else
			node->above_median = false;
		node = node->next;
		i++;
	}
}

void	set_target_node(t_stack *a, t_stack *b)
{
	t_stack		*stack_a;
	t_stack		*target_node;
	long		best_match_value;

	while (b)
	{
		best_match_value = LONG_MAX;
		stack_a = a;
		while (stack_a)
		{
			if (stack_a->value > b->value && stack_a->value < best_match_value)
			{
				best_match_value = stack_a->value;
				target_node = stack_a;
			}
			stack_a = stack_a->next;
		}
		if (best_match_value == LONG_MAX)
			b->target_node = ft_smallest_value(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}
