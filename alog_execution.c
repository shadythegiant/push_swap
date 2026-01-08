#include "push_swap.h"

static void	ft_rotate_nodes(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
	{
		rr(a, b, true);
	}
	ft_set_position(*a);
	ft_set_position(*b);
}
static void	ft_reverse_rotate_nodes(t_stack **a, t_stack **b,
		t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b, true);
	ft_set_position(*a);
	ft_set_position(*b);
}

void	ft_finish_stack_rotation(t_stack **node, t_stack *top_node,
		char stack_name)
{
	while (*node != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(node, true);
			else
				rra(node, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(node, true);
			else
				rrb(node, true);
		}
	}
}
static void	ft_move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*chapeast_node;

	chapeast_node = ft_cheapest_node(*b);
	if (chapeast_node->above_median && chapeast_node->target_node->above_median)
		ft_rotate_nodes(a, b, chapeast_node);
	else if (!(chapeast_node->above_median)
		&& !(chapeast_node->target_node->above_median))
		ft_reverse_rotate_nodes(a, b, chapeast_node);
	ft_finish_stack_rotation(b, chapeast_node, 'b');
	ft_finish_stack_rotation(a, chapeast_node->target_node, 'a');
	pa(a, b, true);
}

// void	ft_push_swap(t_stack **a, t_stack **b )
// {
// 	t_stack	*smallest_node;
// 	int		a_len;

// 	a_len = ft_stack_size(*a);
// 	if (a_len == 5)
// 			sort_five(a, b);
// 	else
// 	{
// 		while (a_len-- > 3)
// 			pb(a, b, true);
// 	}
// 	sort_three(a);
// 	while (*b)
// 	{
// 		ft_init_nodes(*a, *b);
// 		ft_move_nodes(a, b);
// 	}
// 	ft_set_position(*a);
// 	smallest_node = ft_smallest_value(*a);
// 	if (smallest_node->above_median)
// 		while (*a != smallest_node)
// 			ra(a, true);
// 	else
// 		while (*a != smallest_node)
// 			rra(a, true);
// }


void ft_push_swap(t_stack **a, t_stack **b)
{
    t_stack *smallest_node;
    int     a_len;

    a_len = ft_stack_size(*a);
    if (a_len == 5)
        sort_five(a, b);
    else
    {
        // 1. Identify the Keeper Nodes
        ft_mark_lis(*a);
        
        // 2. Push everything else (Fixed: No >3 limit)
        push_all_save_lis(a, b);
    }

    // REMOVED: sort_three(a); 
    // Reason: Stack A contains ONLY the LIS now, so it is already sorted!

    // 3. Turk Loop
    while (*b)
    {
        ft_init_nodes(*a, *b);
        ft_move_nodes(a, b); // Make sure you also applied the "rrr" Fix I gave earlier!
    }

    // 4. Final Alignment
    ft_set_position(*a);
    smallest_node = ft_smallest_value(*a);
    if (smallest_node->above_median)
        while (*a != smallest_node)
            ra(a, true);
    else
        while (*a != smallest_node)
            rra(a, true);
}
