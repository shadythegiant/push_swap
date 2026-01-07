#include "push_swap.h"

void	ft_set_position(t_stack *node)
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

void	ft_set_target_node(t_stack *a, t_stack *b)
{
	t_stack	*stack_a;
	t_stack	*target_node;
	long	best_match_value;

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
void	ft_set_price(t_stack *a, t_stack *b)
{
	int	a_len;
	int	b_len;

	a_len = ft_stack_size(a);
	b_len = ft_stack_size(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->above_median))
			b->push_price = b_len - (b->current_position);
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += a_len - (b->target_node->current_position);
		b = b->next;
	}
}
void	ft_set_cheapest(t_stack *node)
{
	long	best_match_value;
	t_stack	*best_match_node;

	if (node == NULL)
		return ;
	best_match_value = LONG_MAX;
	while (node)
	{
		if (node->push_price < best_match_value)
		{
			best_match_value = node->push_price;
			best_match_node = node;
		}
		node = node->next;
	}
	best_match_node->cheapest = true;
}

void	ft_init_nodes(t_stack *a, t_stack *b)
{
	ft_set_position(a);
	ft_set_position(b);
	ft_set_target_node(a, b);
	ft_set_price(a, b);
	ft_set_cheapest(b);
}
