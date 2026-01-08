/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahidi <azahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:05:30 by azahidi           #+#    #+#             */
/*   Updated: 2025/10/22 17:05:32 by azahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	char		digit[200];
	int			index;

	nb = n;
	index = 0;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	while (nb)
	{
		digit[index++] = '0' + (nb % 10);
		nb = nb / 10;
	}
	while (--index >= 0)
		ft_putchar_fd(digit[index], fd);
}
