#include "push_swap.h"

bool is_sorted(t_stack *head)
{
	if(head == NULL)
		return (true); 
	while(head->next) 
	{
		if(head->value > head->next->value)
			return (false); 
		head = head->next; 	
	}	
	return (true); 
}

