#include "push_swap.h"

static	ft_push(t_stack **src, t_stack **dest)
{
	t_stack  *node; 
	if(*src == NULL || dest == NULL || src == NULL)
		return; 
	// save the  top node of the src in node to push 
	node = *src; 
	// move src p to next to remove the first node; 
	*src = (*src)->next; 	
	// update the src p to be the new head; 
	if(*src)	
		(*src)->prev = NULL; 
	node->prev = NULL; 
	if(*dest == NULL)
	{
		*dest = node; 
		node->next = NULL; 
	}	
	else 
	{
		node->next = *dest; 
		node->next->prev = node; 
		*dest = node; 
	}
}

void pa(t_stack **a, t_stack **b, bool print) 
{
	ft_push(b , a); 
	if(print)
		ft_printf("pa\n"); 
}

void pb(t_stack **a, t_stack **b, bool  print)
{
	ft_push(a, b); 
	if(print)
		ft_printf("pb\n"); 
}