/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahidi <azahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:24:21 by azahidi           #+#    #+#             */
/*   Updated: 2025/09/19 17:24:23 by azahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr = (const unsigned char *)src;

	if (n == 0 || dest == src)
		return (dest);
	dest_ptr = (unsigned char *)dest;
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			dest_ptr[i] = src_ptr[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
		{
			dest_ptr[n] = src_ptr[n];
		}
	}
	return (dest);
}
