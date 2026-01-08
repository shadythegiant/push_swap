/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahidi <azahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:22:33 by azahidi           #+#    #+#             */
/*   Updated: 2025/10/22 15:22:36 by azahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_countdigits(int n)
{
	size_t	counter;
	long	nb;

	counter = 0;
	nb = n;
	if (nb == 0)
		return (1);
	if (n < 0)
	{
		counter++;
		nb = -nb;
	}
	while (nb)
	{
		nb = nb / 10;
		counter++;
	}
	return (counter);
}

static char	*ft_fillstr(char *s, int n)
{
	size_t	size;
	int		counter;
	int		start;
	long	nb;

	size = ft_countdigits(n);
	counter = size - 1;
	nb = n;
	if (nb < 0)
	{
		start = 1;
		nb = -nb;
		s[0] = '-';
	}
	else
		start = 0;
	while (counter >= start)
	{
		s[counter] = (nb % 10) + '0';
		nb = nb / 10;
		counter--;
	}
	s[size] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	size_t	digit_count;
	char	*str;

	digit_count = ft_countdigits(n);
	str = malloc(digit_count + 1);
	if (!str)
		return (NULL);
	str = ft_fillstr(str, n);
	return (str);
}
