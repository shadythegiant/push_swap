/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahidi <azahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 20:33:51 by azahidi           #+#    #+#             */
/*   Updated: 2025/11/09 20:33:53 by azahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_hex(unsigned long n, int uppercase)
{
	char	buffer[20];
	char	*hex;
	int		count;
	int		i;

	if (uppercase)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n == 0)
		return (ft_putchar('0'));
	i = 0;
	while (n > 0)
	{
		buffer[i++] = hex[n % 16];
		n = n / 16;
	}
	count = 0;
	while (i > 0)
		count += ft_putchar(buffer[--i]);
	return (count);
}

int	ft_putptr(void *n)
{
	if (n == NULL)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_print_hex((unsigned long)n, 0));
}

int	ft_putunbr(unsigned int n)
{
	if (n > 9)
		return (ft_putunbr(n / 10) + ft_putchar((n % 10) + '0'));
	else
		return (ft_putchar(n + '0'));
}

int	ft_putnbr(int n)
{
	long	nbr;
	int		count;

	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		count += ft_putnbr(nbr / 10);
		count += ft_putchar((nbr % 10) + '0');
		return (count);
	}
	else
		return (count + ft_putchar(nbr + '0'));
}
