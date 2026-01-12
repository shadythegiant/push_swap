/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS_optimization.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahidi <azahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:38:15 by azahidi           #+#    #+#             */
/*   Updated: 2026/01/12 16:38:19 by azahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_lisflags(int **lis_flags, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		(*lis_flags)[i] = 0;
		i++;
	}
}

void	ft_mark_lis(t_stack *a)
{
	int		*arr;
	int		*lis_flags;
	int		size;
	int		i;
	t_stack	*tmp;

	size = ft_stack_size(a);
	arr = list_to_array(a, size);
	lis_flags = malloc(sizeof(int) * size);
	init_lisflags(&lis_flags, size);
	calculate_lis_indices(arr, size, &lis_flags);
	tmp = a;
	i = 0;
	while (tmp)
	{
		if (lis_flags[i] == 1)
			tmp->is_in_lis = true;
		else
			tmp->is_in_lis = false;
		tmp = tmp->next;
		i++;
	}
	free(arr);
	free(lis_flags);
}

void	push_all_save_lis(t_stack **a, t_stack **b)
{
	int	size;
	int	pushed_count;
	int	i;

	size = ft_stack_size(*a);
	pushed_count = 0;
	i = 0;
	while (size > 0 && i < size)
	{
		if ((*a)->is_in_lis == false)
		{
			pb(a, b, true);
			pushed_count++;
		}
		else
		{
			ra(a, true);
		}
		i++;
	}
}
