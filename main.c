#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack 		*a;
	t_stack			*b;

	a = NULL;
	b = NULL;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);

	if (argc == 2)
		init_stack(&a, ft_split(argv[1], ' '), true);
	else
		init_stack(&a, argv + 1, false);
	if(!(is_sorted(a)))
	{
		if(ft_stack_size(a)  == 2)
			sa(&a, true); 
		else if (ft_stack_size(a) == 3)
			sort_three(&a); 
		else 
			ft_push_swap(&a, &b); 		
	}	
	ft_clean_stack(&a); 
}