#include "push_swap.h"

static int *list_to_array(t_stack *stack , int size )
{
	int		*arr; 
	int		i; 

	i = 0; 
	arr = malloc(sizeof(int) * size); 
	if(!arr)
		return NULL; 
	while(stack)
	{
		arr[i] = stack->value; 
		stack = stack->next; 
		i++; 
	}	
	return (arr); 
}

