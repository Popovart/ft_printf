/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:39:48 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/08 16:40:48 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_output_and_print(t_flags *flags)
{
	int	count;

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
