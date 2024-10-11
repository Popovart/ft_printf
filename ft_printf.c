/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:46:30 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/11 18:47:50 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	char	*fmt_ptr;
	int		count;
	int		shift;

	va_start(args, fmt);
	fmt_ptr = (char *)fmt;
	count = 0;
	while (*fmt_ptr)
	{
		if (*fmt_ptr == '%')
		{
			if (*(fmt_ptr + 1) == '%')
				count += write(1, fmt_ptr++, 1);
			else
			{
				shift = ft_printf_format(fmt_ptr + 1, args, &count);
				if (shift == -1)
					break ;
				fmt_ptr += shift + 1;
			}
		}
		else
			count += write(1, fmt_ptr, 1);
		fmt_ptr++;
	}
	va_end(args);
	return (count);
}

// handle case %% -> %