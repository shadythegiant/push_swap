/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahidi <azahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 20:34:08 by azahidi           #+#    #+#             */
/*   Updated: 2025/11/09 20:34:10 by azahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
#include "../libft/libft.h"


int		ft_printf(const char *format, ...);
char	*ft_strchr(const char *s, int c);
int		ft_putchar(char c);
int		ft_putstr(const char *s);
int		ft_print_hex(unsigned long n, int uppercase);
int		ft_putptr(void *n);
int		ft_putunbr(unsigned int n);
int		ft_putnbr(int n);

#endif
