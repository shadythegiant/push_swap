/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahidi <azahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:39:11 by azahidi           #+#    #+#             */
/*   Updated: 2026/01/12 16:39:15 by azahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *head)
{
	if (head == NULL)
		return (true);
	while (head->next)
	{
		if (head->value > head->next->value)
			return (false);
		head = head->next;
	}
	return (true);
}

t_stack	*find_max(t_stack *node)
{
	t_stack	*max_node;
	long	max_value;

	if (node == NULL)
		return (NULL);
	max_value = LONG_MIN;
	while (node)
	{
		if (node->value > max_value)
		{
			max_value = node->value;
			max_node = node;
		}
		node = node->next;
	}
	return (max_node);
}

void	sort_three(t_stack **head)
{
	t_stack	*max_node;

	if (*head == NULL || head == NULL || (*head)->next == NULL)
		return ;
	max_node = find_max(*head);
	if (*head == max_node)
		ra(head, true);
	else if ((*head)->next == max_node)
		rra(head, true);
	if ((*head)->value > (*head)->next->value)
		sa(head, true);
}

void	sort_five(t_stack **a, t_stack **b)
{
	while (ft_stack_size(*a) > 3)
	{
		ft_init_nodes(*a, *b);
		ft_finish_stack_rotation(a, ft_smallest_value(*a), 'a');
		pb(a, b, true);
	}
	sort_three(a);
	while (*b)
	{
		pa(a, b, true);
	}
}
