/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahidi <azahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:38:01 by azahidi           #+#    #+#             */
/*   Updated: 2026/01/12 16:38:04 by azahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **a, char **argv, bool split_argv)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (ft_is_validinput(argv[i]))
			ft_cleanup(a, argv, split_argv);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_cleanup(a, argv, split_argv);
		if (ft_find_duplicates(*a, (int)nbr))
			ft_cleanup(a, argv, split_argv);
		ft_append_node(a, (int)nbr);
		i++;
	}
	if (split_argv)
		ft_clean_argv(argv);
}
