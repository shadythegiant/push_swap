/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahidi <azahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:38:31 by azahidi           #+#    #+#             */
/*   Updated: 2026/01/12 16:38:33 by azahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*list_to_array(t_stack *stack, int size)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (stack)
	{
		arr[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (arr);
}

int	init_arrays(int size, int **len, int **sub_seq)
{
	int	i;

	*len = malloc(sizeof(int) * size);
	*sub_seq = malloc(sizeof(int) * size);
	if (!(*len) || !(*sub_seq))
		return (0);
	i = 0;
	while (i < size)
	{
		(*len)[i] = 1;
		(*sub_seq)[i] = -1;
		i++;
	}
	return (1);
}

void	fill_lis_arrays(int *arr, int size, int *len, int *sub_seq)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && len[i] < len[j] + 1)
			{
				len[i] = len[j] + 1;
				sub_seq[i] = j;
			}
			j++;
		}
		i++;
	}
}

void	mark_lis_path(int size, int *len, int *sub_seq, int **lis_flags)
{
	int	i;
	int	max_len;
	int	best_end;

	i = 0;
	max_len = 0;
	best_end = 0;
	while (i < size)
	{
		if (len[i] > max_len)
		{
			max_len = len[i];
			best_end = i;
		}
		i++;
	}
	i = best_end;
	while (i != -1)
	{
		(*lis_flags)[i] = 1;
		i = sub_seq[i];
	}
}

void	calculate_lis_indices(int *arr, int size, int **lis_flags)
{
	int	*len;
	int	*sub_seq;

	if (!init_arrays(size, &len, &sub_seq))
	{
		if (len)
			free(len);
		if (sub_seq)
			free(sub_seq);
		return ;
	}
	fill_lis_arrays(arr, size, len, sub_seq);
	mark_lis_path(size, len, sub_seq, lis_flags);
	free(len);
	free(sub_seq);
}
