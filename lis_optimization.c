#include "push_swap.h"

static int	*list_to_array(t_stack *stack, int size)
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

static int	init_arrays(int size, int **len, int **sub_seq)
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
static void	fill_lis_arrays(int *arr, int size, int *len, int *sub_seq)
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
static void	mark_lis_path(int size, int *len, int *sub_seq, int **lis_flags)
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
static void	calculate_lis_indices(int *arr, int size, int **lis_flags)
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
	i = -1;
	while (++i < size)
		lis_flags[i] = 0;
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
	int		size;
	int		pushed_count;
	int		i;

	size = ft_stack_size(*a);
	pushed_count = 0;
	i = 0;
	
	// We iterate through the original size of the stack
	// to check every single node once.
	while (size > 0 && i < size ) 
	{
		if ((*a)->is_in_lis == false)
		{
			pb(a, b, true);
			pushed_count++;
		}
		else
		{
			ra(a, true); // Rotate to keep the LIS node at the bottom for now
		}
		i++;
	}
}