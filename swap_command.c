#include "push_swap.h"

static void	ft_swap(t_stack **head)
{
	t_stack	*first_node;
	t_stack	*second_node;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	first_node = *head;
	second_node = first_node->next;
	if (second_node->next)
		second_node->next->prev = first_node;
	first_node->prev = second_node;
	first_node->next = second_node->next;
	second_node->prev = NULL;
	second_node->next = first_node;
	*head = second_node;
}
void	sa(t_stack **a, bool print)
{
	ft_swap(a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_stack **b, bool print)
{
	ft_swap(b);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, bool print)
{
	ft_swap(a);
	ft_swap(b);
	if (print)
		ft_printf("ss\n");
}
