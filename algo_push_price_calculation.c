/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_push_price_calculation.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahidi <azahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:37:10 by azahidi           #+#    #+#             */
/*   Updated: 2026/01/16 17:37:15 by azahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_calculate_cost(t_stack *b, int len_a, int len_b)
{
	int	target_price;

	b->push_price = b->current_position;
	if (!(b->above_median))
		b->push_price = len_b - b->current_position;
	target_price = b->target_node->current_position;
	if (!(b->target_node->above_median))
		target_price = len_a - b->target_node->current_position;
	if (b->above_median == b->target_node->above_median)
	{
		if (target_price > b->push_price)
			b->push_price = target_price;
	}
	else
		b->push_price += target_price;
}
