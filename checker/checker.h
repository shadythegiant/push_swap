/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahidi <azahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:12:14 by azahidi           #+#    #+#             */
/*   Updated: 2026/01/13 11:12:18 by azahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define BUFFER_SIZE 4

# include "../push_swap.h"
# include <fcntl.h>

char	*ft_strndup(const char *s, size_t n);
ssize_t	gnl_strchr(const char *s, int c);
char	*get_next_line(int fd);

#endif
