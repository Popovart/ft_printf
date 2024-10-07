/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:42:41 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/07 21:52:29 by dmitrii          ###   ########.fr       */
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
	flags->result = NULL;
}

void	ft_putlstchar(void *c)
{
	write(1, (char *)c, 1);
}

void	print_flags(t_flags *flags)
{
	printf("Flags structure:\n");
	printf("minus_flag: %d\n", flags->minus_flag);
	printf("zero_flag: %d\n", flags->zero_flag);
	printf("min_width: %d\n", flags->min_width);
	printf("sign: %c\n", flags->sign ? flags->sign : 'N');
	printf("precision: %d\n", flags->precision);
	printf("hash_flag: %d\n", flags->hash_flag);
	printf("result list\n");
	fflush(stdout);
	ft_lstiter(flags->result, ft_putlstchar);
	printf("lst size: %d\n", ft_lstsize(flags->result));
	printf("\n");
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

int	ft_process_precision(char **fmt_ptr, int *zero_flag, int *shift)
{
	int	precision;

	precision = ft_extract_num(fmt_ptr, shift);
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

int	ft_recalculate_flagnum(int flagnum, const int num_len)
{
	if (flagnum > num_len)
		flagnum -= num_len;
	else
		flagnum = 0;
	return (flagnum);
}

int	ft_print_decimal_type(t_flags *flags)
{
	int	count;

	count = ft_lstsize(flags->result);
	if (flags->minus_flag)
	{
		ft_lstiter(flags->result, ft_putlstchar);
		count += ft_align(' ', flags->min_width);
	}
	else
	{
		count += ft_align(' ', flags->min_width);
		ft_lstiter(flags->result, ft_putlstchar);
	}
	return (count);
}

int	ft_add_numtolst(t_list **lst, char *num)
{
	t_list	*node;

	while (*num)
	{
		node = ft_lstnew(num++);
		if (!node)
			return (ft_lstclear(lst, &free), 0);
		ft_lstadd_back(lst, node);
	}
	return (1);
}

int	ft_add_signtolst(t_list **lst, const char sign)
{
	t_list	*node;

	if (sign)
	{
		if (sign == '+')
			node = ft_lstnew(ft_strdup("+"));
		else if (sign == ' ')
			node = ft_lstnew(ft_strdup(" "));
		else if (sign == '-')
			node = ft_lstnew(ft_strdup("-"));
		if (!node)
			return (ft_lstclear(lst, &free), 0);
		ft_lstadd_front(lst, node);
	}
	return (1);
}

int	ft_add_zerosandsigntolst(t_list **lst, int flagnum, const char sign)
{
	t_list	*node;

	flagnum = ft_recalculate_flagnum(flagnum, ft_lstsize(*lst));
	while (flagnum-- > 0)
	{
		node = ft_lstnew(ft_strdup("0"));
		if (!node)
			return (ft_lstclear(lst, &free), 0);
		ft_lstadd_front(lst, node);
	}
	if (!ft_add_signtolst(lst, sign))
		return (0);
	return (1);
}

// I need to handle when I receive
//	-1 in ft_add_zerosandsigntolst and ft_add_zerosandsigntolst,
//	but now I omit it
int	ft_process_decimal_type(va_list args, t_flags *flags)
{
	int		count;
	long	decimal_num;

	decimal_num = va_arg(args, int);
	if (decimal_num < 0)
	{
		flags->sign = '-';
		decimal_num *= -1;
	}
	ft_add_numtolst(&flags->result, ft_itoa(decimal_num));
	if (flags->precision != -1)
		ft_add_zerosandsigntolst(&flags->result, flags->precision, flags->sign);
	else if (flags->zero_flag)
	{
		ft_add_zerosandsigntolst(&flags->result, flags->min_width, flags->sign);
		flags->min_width = 0;
	}
	else
		ft_add_signtolst(&flags->result, flags->sign);
	flags->min_width = ft_recalculate_flagnum(flags->min_width,
			ft_lstsize(flags->result));
	count = ft_print_decimal_type(flags);
	return (count);
}

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
				&shift);
	}
	if (*fmt_ptr == 'd' || *fmt_ptr == 'i')
		*count += ft_process_decimal_type(args, &flags);
	else if (*fmt_ptr == 'c')
		*count += ft_char_format(args);
	// else if (*fmt_ptr == 's')
	// *count += ft_string_format(args, flags.min_width, align_format);
	return (shift);
}
