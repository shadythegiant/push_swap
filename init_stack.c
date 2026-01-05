#include "push_swap.h"

void	init_stack(t_stack **a, char **argv, bool split_argv)
{
	long nbr;
	int i;

	i = 0;
	while (argv[i])
	{
		// check for valid input
		if (ft_is_validinput(argv[i]))
			ft_cleanup(a, argv, split_argv);
		nbr = ft_atol(argv[i]);
		//
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_cleanup(a, argv, split_argv);
		if (ft_find_duplicates(*a, (int)nbr))
			ft_cleanup(a, argv, split_argv);
		// appending the node
		ft_append_node(a, (int)nbr);
		i++;
	}
	if (split_argv)
		ft_clean_argv(argv);
}