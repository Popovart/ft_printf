/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_output_and_print.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:39:48 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/11 20:24:57 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_output_and_print(t_flags *flags)
{
	int	count;

	if (flags->precision != -1)
	{
		if (ft_add_zerostolst(&flags->result, flags->precision,
				flags->zero_flag, flags->sign) == -1)
			return (-1);
	}
	else if (flags->zero_flag)
	{
		if (ft_add_zerostolst(&flags->result, flags->min_width,
				flags->zero_flag, flags->sign) == -1)
			return (-1);
		flags->min_width = 0;
	}
	if (ft_add_signtolst(&flags->result, flags->sign) == -1)
		return (-1);
	flags->min_width = ft_recalculate_flagnum(flags->min_width,
			ft_lstsize(flags->result));
	count = ft_print_type_with_align(flags);
	return (count);
}
