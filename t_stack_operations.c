#include "push_swap.h"

t_stack	*ft_stacklast(t_stack *head)
{
	t_stack	*last;

	if (head == NULL)
		return (NULL);
	last = head;
	while (last->next)
		last = last->next;
	return (last);
}

void	ft_append_node(t_stack **stack, int nbr)
{
	t_stack	*node;
	t_stack	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->value = (int)nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_stacklast(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

int	ft_stack_size(t_stack *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

t_stack	*ft_smallest_value(t_stack *node)
{
	long	smallest;
	t_stack	*smallest_node;

	smallest = LONG_MAX;
	while (node)
	{
		if (node->value < smallest)
		{
			smallest = node->value;
			smallest_node = node;
		}
		node = node->next;
	}
	return (smallest_node);
}

t_stack	*ft_cheapest_node(t_stack *node)
{
	if (node == NULL)
		return (NULL);
	while (node)
	{
		if (node->cheapest)
			return (node);
		node = node->next;
	}
	return (NULL);
}
