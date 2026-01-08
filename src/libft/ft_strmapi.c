/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahidi <azahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:22:53 by azahidi           #+#    #+#             */
/*   Updated: 2025/10/22 15:22:55 by azahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	size_t			size;
	char			*new_string;

	if (!s || !f)
		return (NULL);
	index = 0;
	size = ft_strlen(s);
	new_string = malloc(size + 1);
	if (!new_string)
		return (NULL);
	while (s[index])
	{
		new_string[index] = f(index, s[index]);
		index++;
	}
	new_string[index] = '\0';
	return (new_string);
}
