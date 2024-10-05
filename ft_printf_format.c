/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:42:41 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/05 19:16:51 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_align(char c, int min_width)
{
	int	count;

	count = 0;
	while (min_width-- > 0)
	{
		write(1, &c, 1);
		count++;
	}
	return (count);
}

// change name of the function
int	ft_minus_format(char **fmt_ptr, int *shift, char *align_format)
{
	int	min_width;

	*align_format = **fmt_ptr;
	(*shift)++;
	min_width = 0;
	while (ft_isdigit(*(++(*fmt_ptr))))
	{
		min_width = min_width * 10 + (**fmt_ptr - '0');
		(*shift)++;
	}
	return (min_width);
}

int	ft_decimal_format(va_list args, int count, int min_width, char align_format)
{
	int	decimal_num;
	int	num_len;

	decimal_num = va_arg(args, int);
	num_len = ft_numlen(decimal_num);
	if (min_width > num_len)
		min_width -= num_len;
	else
		min_width = 0;
	if (align_format == '-')
	{
		ft_putnbr_fd(decimal_num, 1);
		count += ft_align(' ', min_width);
	}
	else if (align_format == '0')
	{
		count += ft_align('0', min_width);
		ft_putnbr_fd(decimal_num, 1);
	}
	return (count + num_len);
}

int	ft_printf_format(char *fmt_ptr, va_list args, int *count)
{
	int		min_width;
	int		shift;
	char	align_format;

	min_width = 0;
	shift = 0;
	if (*fmt_ptr == '-')
		min_width = ft_minus_format(&fmt_ptr, &shift, &align_format);
	else if (*fmt_ptr == '0')
		min_width = ft_minus_format(&fmt_ptr, &shift, &align_format);
	if (*fmt_ptr == 'd')
		*count = ft_decimal_format(args, *count, min_width, align_format);
	return (shift);
}
