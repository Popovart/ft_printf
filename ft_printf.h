/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:45:05 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/05 19:59:01 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"
# include "stddef.h"
# include "stdio.h"
# include "unistd.h"

int		ft_printf(const char *fmt, ...);
int		ft_numlen(int n);
void	ft_putnbr_fd(int n, int fd);
int		ft_printf_format(char *fmt_ptr, va_list args, int *count);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);

#endif