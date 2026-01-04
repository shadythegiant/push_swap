#include "push_swap.h"

static void ft_rotate(t_stack **head)
{
	t_stack		*last_node;
	if(head == NULL || *head == NULL || (*head)->next == NULL)
		return; 
	last_node = ft_stacklast(*head); 
	last_node->next = *head; 
	(*head)->prev = last_node; 
	*head = (*head)->next;
	(*head)->prev = NULL; 
	last_node->next->next = NULL;  
}

void ra(t_stack **a, bool print)
{
    ft_rotate(a);
    if (print)
        ft_printf("ra\n");
}

void rb(t_stack **b, bool print)
{
    ft_rotate(b);
    if (print)
        ft_printf("rb\n");
}

void rr(t_stack **a, t_stack **b, bool print)
{
    ft_rotate(a);
    ft_rotate(b);
    if (print)
        ft_printf("rr\n");
}
