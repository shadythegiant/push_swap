/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahidi <azahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 20:51:22 by azahidi           #+#    #+#             */
/*   Updated: 2025/09/21 20:51:25 by azahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*endptr;

	len = ft_strlen(s);
	endptr = (char *)&s[len];
	while (endptr >= s)
	{
		if (*endptr == (char)c)
		{
			return ((char *)endptr);
		}
		endptr--;
	}
	return (NULL);
}
