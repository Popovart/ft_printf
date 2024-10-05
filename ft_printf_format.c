/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:42:41 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/05 20:21:38 by dmitrii          ###   ########.fr       */
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

/**
 * @brief Counts the minimum width set in
 * the format string and adjusts other parameters.
 *
 * This function scans the format string pointed to by `fmt_ptr` and extracts
 * the minimum width for formatting. It also increments the shift counter and
 * sets the alignment format character.
 *
 * @param fmt_ptr Pointer to the format string,
 * which will be modified during the process.
 * @param shift Pointer to an integer
 * that tracks the current position shift in the format string.
 * @param align_format Pointer to a character
 * where the alignment format will be stored.
 * @return The minimum width extracted from the format string.
 */
int	ft_align_format(char **fmt_ptr, int *shift, char *align_format)
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

int	ft_decimal_format(va_list args, int min_width, char align_format)
{
	int	decimal_num;
	int	num_len;
	int	count;

	decimal_num = va_arg(args, int);
	num_len = ft_numlen(decimal_num);
	count = num_len;
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
	else
		ft_putnbr_fd(decimal_num, 1);
	return (count);
}

int	ft_char_format(va_list args)
{
	char	c;

	c = va_arg(args, int);
	return (write(1, &c, 1));
}

// такая же реализация как и в ft_decimal_format. нужно объединить
int	ft_string_format(va_list args, int min_width, char align_format)
{
	int		strlen;
	char	*str;
	int		count;

	str = va_arg(args, char *);
	strlen = ft_strlen(str);
	count = strlen;
	if (min_width > strlen)
		min_width -= strlen;
	else
		min_width = 0;
	if (align_format == '-')
	{
		ft_putstr_fd(str, 1);
		count += ft_align(' ', min_width);
	}
	else
		ft_putstr_fd(str, 1);
	return (count);
}

int	ft_printf_format(char *fmt_ptr, va_list args, int *count)
{
	int		min_width;
	int		shift;
	char	align_format;

	min_width = 0;
	shift = 0;
	if (*fmt_ptr == '-')
		min_width = ft_align_format(&fmt_ptr, &shift, &align_format);
	else if (*fmt_ptr == '0')
		min_width = ft_align_format(&fmt_ptr, &shift, &align_format);
	if (*fmt_ptr == 'd' || *fmt_ptr == 'i')
		*count += ft_decimal_format(args, min_width, align_format);
	else if (*fmt_ptr == 'c')
		*count += ft_char_format(args);
	else if (*fmt_ptr == 's')
		*count += ft_string_format(args, min_width, align_format);
	return (shift);
}
