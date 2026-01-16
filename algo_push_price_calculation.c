#include "push_swap.h"

void	ft_calculate_cost(t_stack *b, int len_a, int len_b)
{
	int	target_price;

	// 1. Cost for B
	b->push_price = b->current_position;
	if (!(b->above_median))
		b->push_price = len_b - b->current_position;
	
	// 2. Cost for A
	target_price = b->target_node->current_position;
	if (!(b->target_node->above_median))
		target_price = len_a - b->target_node->current_position;

	// 3. Optimization: If directions match (Both UP or Both DOWN), use MAX
	if (b->above_median == b->target_node->above_median)
	{
		if (target_price > b->push_price)
			b->push_price = target_price;
	}
	// 4. If directions are mixed (One UP, One DOWN), use SUM
	else
		b->push_price += target_price;
}
