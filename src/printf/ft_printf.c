/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahidi <azahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 20:33:13 by azahidi           #+#    #+#             */
/*   Updated: 2025/11/09 20:33:17 by azahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_format(va_list ap, char **format_str, char specifier)
{
	int	count;

	count = 0;
	if (specifier == '%')
		count += ft_putchar('%');
	else if (specifier == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (specifier == 'u')
		count += ft_putunbr(va_arg(ap, int));
	else if (specifier == 'x' || specifier == 'X')
		count += ft_print_hex(va_arg(ap, unsigned int), specifier == 'X');
	else if (specifier == 'p')
		count += ft_putptr(va_arg(ap, void *));
	*format_str += 2;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	char	*specifier;
	char	*s;

	if (!format)
		return (-1);
	count = 0;
	s = (char *)format;
	va_start(ap, format);
	while (*s)
	{
		if (*s != '%' && ++count)
		{
			write(1, s++, 1);
			continue ;
		}
		specifier = ft_strchr("cspdiuxX%", *(s + 1));
		if (!specifier && ++count)
			write(1, s++, 1);
		else
			count += ft_print_format(ap, &s, *specifier);
	}
	va_end(ap);
	return (count);
}
