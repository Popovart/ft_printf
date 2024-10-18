/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_hex_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:25:17 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/18 15:02:56 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_process_hex_type(va_list args, t_flags *flags, const int is_upper)
{
	int	count;
	int	num;	

	num = va_arg(args, unsigned int);
	if (num != 0 || flags->precision != 0)
	{
		if (ft_add_hextolst(&flags->result, (unsigned int)num, is_upper) == -1)
			return (-1);
		if (flags->hash_flag && num != 0)
		{
			if (is_upper)
				flags->sign = "X0";
			else
				flags->sign = "x0";
		}
	}
	count = ft_format_output_and_print(flags);
	return (count);
}
