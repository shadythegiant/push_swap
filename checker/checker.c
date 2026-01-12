#include "checker.h"

static void		ft_error_free(t_stack **a  , t_stack **b) 
{
	ft_clean_stack(a);
	ft_clean_stack(b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static int ft_strcmp(char *s1 , char *s2 ) 
{
	while(*s1 && *s1 == *s2) 
	{
		s1++;
		s2++;
	}
	return (*s1  - *s2);
}

static void ft_parse(t_stack **a , t_stack **b , char *command) 
{
	
}