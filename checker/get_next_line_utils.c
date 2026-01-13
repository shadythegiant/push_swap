/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahidi <azahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:04:00 by azahidi           #+#    #+#             */
/*   Updated: 2025/11/17 16:04:03 by azahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(n + 1);
	if (!dup)
		return (NULL);
	while (i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

ssize_t	gnl_strchr(const char *s, int c)
{
	size_t	index;

	index = 0;
	while (s[index] && s[index] != (char)c)
		index++;
	if (s[index] == (char)c)
		return (index);
	return (-1);
}
