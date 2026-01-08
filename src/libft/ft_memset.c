/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahidi <azahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:03:54 by azahidi           #+#    #+#             */
/*   Updated: 2025/09/19 16:03:57 by azahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buffer, int c, size_t size)
{
	size_t			counter;
	unsigned char	low8bits;
	unsigned char	*byt_ptr;

	counter = 0;
	low8bits = (unsigned char)c;
	byt_ptr = (unsigned char *)buffer;
	while (counter < size)
	{
		byt_ptr[counter] = low8bits;
		counter++;
	}
	return (buffer);
}
