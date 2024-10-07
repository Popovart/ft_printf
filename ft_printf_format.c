/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:42:41 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/07 16:06:05 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->minus_flag = 0;
	flags->zero_flag = 0;
	flags->min_width = -1;
	flags->sign = '\0';
	flags->precision = -1;
	flags->hash_flag = 0;
}

void	print_flags(const t_flags *flags)
{
	printf("Flags structure:\n");
	printf("minus_flag: %d\n", flags->minus_flag);
	printf("zero_flag: %d\n", flags->zero_flag);
	printf("min_width: %d\n", flags->min_width);
	printf("sign: %c\n", flags->sign ? flags->sign : 'N');
	printf("precision: %d\n", flags->precision);
	printf("hash_flag: %d\n", flags->hash_flag);
}

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

int	ft_extract_num(char **fmt_ptr, int *shift)
{
	int	flag_num;

	flag_num = 0;
	while (ft_isdigit(**fmt_ptr))
	{
		flag_num = flag_num * 10 + (**fmt_ptr - '0');
		(*shift)++;
		(*fmt_ptr)++;
	}
	return (flag_num);
}

int	ft_isflag(char c)
{
	if (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#')
		return (1);
	return (0);
}

int	ft_process_precision(char **fmt_ptr, int *zero_flag, int *min_width,
		int *shift)
{
	int	precision;

	precision = ft_extract_num(fmt_ptr, shift);
	if (*min_width < precision)
		*min_width = precision;
	*zero_flag = 0;
	return (precision);
}

void	ft_process_flags(char **fmt_ptr, t_flags *flags, int *shift)
{
	while (ft_isflag(**fmt_ptr))
	{
		if (**fmt_ptr == '-' && !flags->minus_flag)
			flags->minus_flag = 1;
		else if (**fmt_ptr == '0' && !flags->minus_flag && !flags->zero_flag)
			flags->zero_flag = 1;
		else if (**fmt_ptr == '+' && flags->sign != '+')
			flags->sign = '+';
		else if (**fmt_ptr == ' ' && !flags->sign)
			flags->sign = ' ';
		else if (**fmt_ptr == '#')
			flags->hash_flag = 1;
		(*fmt_ptr)++;
		(*shift)++;
	}
}

int	ft_recalculate_minwidth(int min_width, const int num_len)
{
	if (min_width > num_len)
		min_width -= num_len;
	else
		min_width = 0;
	return (min_width);
}

int	ft_add_sign(char sign, int decimal_num)
{
	if (sign && decimal_num > 0)
		return (write(1, &sign, 1));
	else
		return (0);
}

int	ft_print_decimal_type(int decimal_num, t_flags *flags, int count)
{
	if (flags->sign && decimal_num > 0)
	{
		flags->min_width--;
		count++;
	}
	if (flags->minus_flag)
	{
		ft_add_sign(flags->sign, decimal_num);
		ft_putnbr_fd(decimal_num, 1);
		count += ft_align(' ', flags->min_width);
	}
	else if (flags->zero_flag || flags->precision != -1)
	{
		ft_add_sign(flags->sign, decimal_num);
		count += ft_align('0', flags->min_width);
		ft_putnbr_fd(decimal_num, 1);
	}
	else
	{
		count += ft_align(' ', flags->min_width);
		count += ft_add_sign(flags->sign, decimal_num);
		ft_putnbr_fd(decimal_num, 1);
	}
	return (count);
}

int	ft_process_decimal_type(va_list args, t_flags *flags)
{
	int	count;
	int	decimal_num;
	int	num_len;

	decimal_num = va_arg(args, int);
	num_len = ft_numlen(decimal_num);
	count = num_len;
	flags->min_width = ft_recalculate_minwidth(flags->min_width, num_len);
	count = ft_print_decimal_type(decimal_num, flags, count);
	return (count);
}

// int	ft_decimal_format(va_list args, t_flags *flags, int min_width,
// 		char align_format)
// {
// 	int	decimal_num;
// 	int	num_len;
// 	int	count;

// 	decimal_num = va_arg(args, int);
// 	num_len = ft_numlen(decimal_num);
// 	count = num_len;
// 	if (min_width > num_len)
// 		min_width -= num_len;
// 	else
// 		min_width = 0;
// 	if (align_format == '-')
// 	{
// 		ft_putnbr_fd(decimal_num, 1);
// 		count += ft_align(' ', min_width);
// 	}
// 	else if (align_format == '0' || align_format == '.')
// 	{
// 		count += ft_align(align_format, min_width);
// 		ft_putnbr_fd(decimal_num, 1);
// 	}
// 	else
// 		ft_putnbr_fd(decimal_num, 1);
// 	return (count);
// }

// int	ft_string_format(va_list args, int min_width, char align_format)
// {
// 	int		strlen;
// 	char	*str;
// 	int		count;

// 	str = va_arg(args, char *);
// 	strlen = ft_strlen(str);
// 	count = strlen;
// 	if (min_width > strlen)
// 		min_width -= strlen;
// 	else
// 		min_width = 0;
// 	if (align_format == '-')
// 	{
// 		ft_putstr_fd(str, 1);
// 		count += ft_align(' ', min_width);
// 	}
// 	else
// 		ft_putstr_fd(str, 1);
// 	return (count);
// }

int	ft_char_format(va_list args)
{
	char	c;

	c = va_arg(args, int);
	return (write(1, &c, 1));
}

// сейчас у меня не учитывается вот этот такая комбинация флагов printf("%08.5d\n",
// 42);
// printf("%10.3s\n", "Hello, world!");  min_width флаг не работает еще

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
	{
		fmt_ptr++;
		shift++;
		flags.precision = ft_process_precision(&fmt_ptr, &flags.zero_flag,
				&flags.min_width, &shift);
	}
	if (*fmt_ptr == 'd' || *fmt_ptr == 'i')
		*count += ft_process_decimal_type(args, &flags);
	else if (*fmt_ptr == 'c')
		*count += ft_char_format(args);
	// else if (*fmt_ptr == 's')
	// *count += ft_string_format(args, flags.min_width, align_format);
	return (shift);
}
