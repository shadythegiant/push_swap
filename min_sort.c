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

t_stack *find_max(t_stack *node) 
{ 
	t_stack		*max_node; 
	long		max_value; 
	if(node == NULL  )
		return (NULL); 
	max_value = LONG_MIN; 
	while(node) 
	{
		if(node->value > max_value)
		{
			max_value = node->value; 
			max_node = node; 
		}
		node = node->next; 
	}
	return (max_node); 
}
