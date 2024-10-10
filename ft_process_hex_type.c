/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_hex_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrypopov <dmitrypopov@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:25:17 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/10 15:10:44 by dmitrypopov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_process_hex_type(va_list args, t_flags *flags, const int is_upper)
{
	int	count;
	int	num;

	num = va_arg(args, unsigned int);
	if (ft_add_hextolst(&flags->result, (unsigned int)num, is_upper) == -1)
		return (-1);
	if (flags->hash_flag)
	{
		if (is_upper)
			flags->sign = "X0";
		else
			flags->sign = "x0";
	}
	count = ft_format_output_and_print(flags);
	return (count);
}