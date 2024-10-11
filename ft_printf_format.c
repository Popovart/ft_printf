/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:42:41 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/11 21:29:43 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isupper(const int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_process_types(char **fmt_ptr, t_flags *flags, va_list args, int *count)
{
	int	i;

	i = 0;
	if (**fmt_ptr == 'd' || **fmt_ptr == 'i')
		i += ft_process_decimal_type(args, flags);
	else if (**fmt_ptr == 'c')
		i += ft_process_char_type(args, flags);
	else if (**fmt_ptr == 's')
		i += ft_process_string_type(args, flags);
	else if (**fmt_ptr == 'x' || **fmt_ptr == 'X')
		i += ft_process_hex_type(args, flags, ft_isupper(**fmt_ptr));
	else if (**fmt_ptr == 'p')
		i += ft_process_pointer_type(args, flags);
	else if (**fmt_ptr == 'u')
		i += ft_process_unsdecimal_type(args, flags);
	if (i < 0)
		return (-1);
	else
		*count += i;
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
		flags.precision = ft_process_precision(&fmt_ptr, &flags.zero_flag,
				&shift);
	if (flags.result)
		ft_lstclear(&flags.result, &free);
	if (ft_process_types(&fmt_ptr, &flags, args, count) == -1)
	{
		write(2, "format error\n", 13);
		return (-1);
	}
	return (shift);
}
