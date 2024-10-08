/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_decimal_type.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:12:22 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/08 16:32:22 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		flags->sign = "-";
		decimal_num *= -1;
	}
	ft_add_strtolst(&flags->result, ft_itoa(decimal_num), &ft_lstadd_back);
	if (flags->precision != -1)
		ft_add_zerostolst(&flags->result, flags->precision, flags->sign);
	else if (flags->zero_flag)
	{
		ft_add_zerostolst(&flags->result, flags->min_width, flags->sign);
		flags->min_width = 0;
	}
	ft_add_signtolst(&flags->result, flags->sign);
	flags->min_width = ft_recalculate_flagnum(flags->min_width,
			ft_lstsize(flags->result));
	count = ft_print_type_with_align(flags);
	return (count);
}
