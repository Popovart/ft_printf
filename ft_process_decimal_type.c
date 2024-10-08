/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_decimal_type.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:12:22 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/08 18:32:45 by dmitrii          ###   ########.fr       */
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
	count = ft_format_output_and_print(flags);
	return (count);
}
