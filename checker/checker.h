#ifndef CHECKER_H
#define CHECKER_H

#define BUFFER_SIZE 4

#include "../push_swap.h"
#include <fcntl.h>


char	 *ft_strndup(const char *s, size_t n); 
ssize_t	 ft_strchr(const char *s, int c); 
char	 *get_next_line(int fd);
static int ft_strcmp(char *s1 , char *s2 );
static void		ft_error_free(t_stack **a  , t_stack **b);


#endif