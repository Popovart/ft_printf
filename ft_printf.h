/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:45:05 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/05 15:54:10 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"
# include "stdio.h"
# include "unistd.h"

int	ft_printf(const char *fmt, ...);
int	ft_numlen(int n);
int	ft_putnbr_fd(int n, int fd);
int	ft_printf_format(char *fmt_ptr, va_list args, int *count);
int	ft_isdigit(int c);

#endif