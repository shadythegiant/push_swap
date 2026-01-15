/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahidi <azahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:38:53 by azahidi           #+#    #+#             */
/*   Updated: 2026/01/12 16:38:56 by azahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	init_stack(&a, argv + 1);
	if (!(is_sorted(a)))
	{
		if (ft_stack_size(a) == 2)
			sa(&a, true);
		else if (ft_stack_size(a) == 3)
			sort_three(&a);
		else
			ft_push_swap(&a, &b);
	}
	ft_clean_stack(&a);
}
