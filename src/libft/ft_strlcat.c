/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahidi <azahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:29:35 by azahidi           #+#    #+#             */
/*   Updated: 2025/09/20 16:29:37 by azahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_index;
	size_t	dest_len;
	size_t	src_len;

	dest_len = 0;
	src_len = ft_strlen(src);
	src_index = 0;
	while (dest[dest_len] && dest_len < size)
		dest_len++;
	if (dest_len == size)
		return (dest_len + src_len);
	while (src[src_index] && (dest_len + src_index + 1) < size)
	{
		dest[dest_len + src_index] = src[src_index];
		src_index++;
	}
	dest[dest_len + src_index] = '\0';
	return (src_len + dest_len);
}
