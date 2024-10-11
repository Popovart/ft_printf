/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrypopov <dmitrypopov@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:42:41 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/11 15:17:06 by dmitrypopov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char_format(va_list args)
{
	char	c;

	c = va_arg(args, int);
	return (write(1, &c, 1));
}

int	ft_isupper(const int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_printf_format(char *fmt_ptr, va_list args, int *count)
{
	t_flags	flags;
	int		shift;

	shift = 0;
	init_flags(&flags);
	ft_process_flags(&fmt_ptr, &flags, &shift);
	if (ft_isdigit(*fmt_ptr))
		flags.min_width = ft_extract_num(&fmt_ptr, &shift);
	if (*fmt_ptr == '.')
		flags.precision = ft_process_precision(&fmt_ptr, &flags.zero_flag, &shift);
	if (*fmt_ptr == 'd' || *fmt_ptr == 'i')
		*count += ft_process_decimal_type(args, &flags);
	else if (*fmt_ptr == 'c')
		*count += ft_char_format(args);
	else if (*fmt_ptr == 's')
		*count += ft_process_string_type(args, &flags);
	else if (*fmt_ptr == 'x' || *fmt_ptr == 'X')
		*count += ft_process_hex_type(args, &flags, ft_isupper(*fmt_ptr));
	else if (*fmt_ptr == 'p')
		*count += ft_process_pointer_type(args, &flags);
	else if (*fmt_ptr == 'u')
		*count += ft_process_unsdecimal_type(args, &flags);
	return (shift);
}
