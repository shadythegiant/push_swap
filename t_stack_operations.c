#include "push_swap.h"


t_stack *ft_stacklast(t_stack *head)
{ 
	t_stack		*last;

	if(head == NULL)
		return NULL; 
	last = head; 
	while (last->next) 
		last = last->next; 
	return (last); 		
}

void ft_append_node(t_stack **stack , int nbr) 
{ 
	t_stack		*node; 
	t_stack		*last_node; 

	if(stack == NULL)
		return; 
	node = malloc(sizeof(t_stack)); 
	if(!node)
		return; 
	node->next = NULL; 
	node->value = (int)nbr; 
	if(*stack == NULL)
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