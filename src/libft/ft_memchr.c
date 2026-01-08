/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahidi <azahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:07:13 by azahidi           #+#    #+#             */
/*   Updated: 2025/09/28 17:07:16 by azahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	size_t				i;
	const unsigned char	*s_ptr = (const unsigned char *)s ;
	unsigned char		target_mask;

	target_mask = c & 0xFF;
	i = 0;
	while (i < size)
	{
		if (s_ptr[i] == target_mask)
		{
			return ((void *)(s_ptr + i));
		}
		i++;
	}
	return (NULL);
}
