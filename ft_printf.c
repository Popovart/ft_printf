/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:46:30 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/05 16:05:42 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	char	*fmt_ptr;
	int		count;

	// I don't know what it must return actually in this case
	if (!fmt)
		return (-1);
	va_start(args, fmt);
	fmt_ptr = (char *)fmt;
	count = 0;
	while (*fmt_ptr)
	{
		if (*fmt_ptr == '%')
		{
			fmt_ptr += ft_printf_format(fmt_ptr + 1, args, &count) + 1;
		}
		else
		{
			count = write(1, fmt_ptr, 1);
		}
		fmt_ptr++;
	}
	va_end(args);
	return (count);
}

// handle case %% -> %