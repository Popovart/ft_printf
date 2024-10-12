/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_decimal_type.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:12:22 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/12 19:22:17 by dmitrii          ###   ########.fr       */
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
	char	*num_str;

	decimal_num = va_arg(args, int);
	if (decimal_num < 0 && decimal_num != -2147483648)
	{
		flags->sign = "-";
		decimal_num *= -1;
	}
	if (decimal_num != 0 || flags->precision != 0)
	{
		if (decimal_num == -2147483648)
			num_str = ft_strdup("-2147483648");
		else
			num_str = ft_itoa(decimal_num);
		if (ft_add_strtolst(&flags->result, num_str, &ft_lstadd_back) == -1)
			return (-1);
	}
	count = ft_format_output_and_print(flags);
	return (count);
}
