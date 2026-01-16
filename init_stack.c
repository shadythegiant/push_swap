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

static void	process_tokens(t_stack **a, char **tokens)
{
	int		i;
	long	nbr;

	i = 0;
	while (tokens[i])
	{
		if (ft_is_validinput(tokens[i]))
			ft_cleanup(a, tokens, true);
		nbr = ft_atol(tokens[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_cleanup(a, tokens, true);
		if (ft_find_duplicates(*a, (int)nbr))
			ft_cleanup(a, tokens, true);
		ft_append_node(a, (int)nbr);
		i++;
	}
}

static void	parse_arguments(t_stack **a, char *arg)
{
	char	**tokens;

	tokens = ft_split(arg, ' ');
	if (!tokens)
		ft_cleanup(a, NULL, false);
	if (!tokens[0])
		ft_cleanup(a, tokens, true);
	process_tokens(a, tokens);
	ft_clean_argv(tokens);
}

void	init_stack(t_stack **a, char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		parse_arguments(a, argv[i]);
		i++;
	}
}
