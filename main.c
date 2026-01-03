#include "push_swap.h"

void print_stack(t_stack *stack) { 
	if(stack == NULL)
		return; 
	while(stack) 
	{ 
		ft_printf("%d \n", stack->value); 
		stack = stack->next; 
	}	
}
int main(int argc , char **argv) 
{ 
	t_stack			*a; 
	// t_stack		*b; 

	a = NULL;
	// b = NULL; 

	if(argc == 1 || (argc == 2 && !argv[1][0]))
		return 1; 
	
	 if (argc == 2) 
		init_stack(&a, ft_split(argv[1], ' '), true); 
	else 
		init_stack(&a, argv + 1, false); 
	print_stack(a); 
	ft_printf("%d \n", ft_stack_size(a)); 	
}