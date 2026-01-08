/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahidi <azahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:43:24 by azahidi           #+#    #+#             */
/*   Updated: 2025/10/19 19:43:26 by azahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_wordcount(char const *s, char delimeter)
{
	size_t	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == delimeter)
			s++;
		if (*s)
			word_count++;
		while (*s && *s != delimeter)
			s++;
	}
	return (word_count);
}

static size_t	ft_freeallocation(char **strings, size_t position, size_t len)
{
	size_t	counter;

	counter = 0;
	strings[position] = malloc(len);
	if (!strings[position])
	{
		while (counter < position)
		{
			free(strings[counter++]);
		}
		free(strings);
		return (1);
	}
	return (0);
}

static size_t	ft_allocate(char **strings, char const *s, char delimeter)
{
	size_t	len;
	size_t	position;

	position = 0;
	while (*s)
	{
		len = 0;
		while (*s && *s == delimeter)
			s++;
		while (*s && *s != delimeter)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (ft_freeallocation(strings, position, len + 1))
				return (1);
			ft_strlcpy(strings[position], (s - len), (len + 1));
		}
		position++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	**strings;

	if (!s)
		return (NULL);
	word_count = ft_wordcount(s, c);
	strings = malloc(sizeof(char *) * (word_count + 1));
	if (!strings)
		return (NULL);
	strings[word_count] = NULL;
	if (ft_allocate(strings, s, c))
		return (NULL);
	return (strings);
}
