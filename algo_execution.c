/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahidi <azahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:37:21 by azahidi           #+#    #+#             */
/*   Updated: 2026/01/12 16:37:27 by azahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest_node;
	int		a_len;

	a_len = ft_stack_size(*a);
	if (a_len == 5)
		sort_five(a, b);
	else
	{
		ft_mark_lis(*a);
		push_all_save_lis(a, b);
	}
	while (*b)
	{
		ft_init_nodes(*a, *b);
		ft_move_nodes(a, b);
	}
	ft_set_position(*a);
	smallest_node = ft_smallest_value(*a);
	if (smallest_node->above_median)
		while (*a != smallest_node)
			ra(a, true);
	else
		while (*a != smallest_node)
			rra(a, true);
}
