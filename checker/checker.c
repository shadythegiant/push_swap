/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahidi <azahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:11:59 by azahidi           #+#    #+#             */
/*   Updated: 2026/01/13 11:12:02 by azahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_error_free(t_stack **a, t_stack **b, char *line)
{
	if (line)
		free(line);
	ft_clean_stack(a);
	ft_clean_stack(b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static void	ft_parse(t_stack **a, t_stack **b, char *command)
{
	if (!ft_strcmp(command, "pa\n"))
		pa(a, b, false);
	else if (!ft_strcmp(command, "pb\n"))
		pb(a, b, false);
	else if (!ft_strcmp(command, "sa\n"))
		sa(a, false);
	else if (!ft_strcmp(command, "sb\n"))
		sb(a, false);
	else if (!ft_strcmp(command, "ss\n"))
		ss(a, b, false);
	else if (!ft_strcmp(command, "ra\n"))
		ra(a, false);
	else if (!ft_strcmp(command, "rb\n"))
		rb(b, false);
	else if (!ft_strcmp(command, "rr\n"))
		rr(a, b, false);
	else if (!ft_strcmp(command, "rra\n"))
		rra(a, false);
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(b, false);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(a, b, false);
	else
		ft_error_free(a, b, command);
}

static void	ft_process_line(char *line, t_stack **a, t_stack **b)
{
	while (line)
	{
		ft_parse(a, b, line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		len;
	char	*line;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		init_stack(&a, ft_split(argv[1], ' '), true);
	else
		init_stack(&a, argv + 1, false);
	len = ft_stack_size(a);
	line = get_next_line(0);
	ft_process_line(line, &a, &b);
	if (is_sorted(a) && ft_stack_size(a) == len)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_clean_stack(&a);
	ft_clean_stack(&b);
}
