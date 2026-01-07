#include "push_swap.h"

static void	ft_reverse_rotate(t_stack **head)
{
	t_stack	*last_node;

	if (NULL == head || NULL == *head || NULL == (*head)->next)
		return ;
	last_node = ft_stacklast(*head);
	last_node->prev->next = NULL;
	last_node->next = *head;
	(*head)->prev = last_node;
	*head = last_node;
	(*head)->prev = NULL;
}

void	rra(t_stack **a, bool print)
{
	ft_reverse_rotate(a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, bool print)
{
	ft_reverse_rotate(b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	if (print)
		ft_printf("rrr\n");
}