/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_char_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:24:51 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/18 13:56:20 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_process_char_type(va_list args, t_flags *flags)
{
	int	c;
	int	count;

	c = va_arg(args, int);
	if (ft_add_chartolst(&flags->result, c, &ft_lstadd_back) == -1)
		return (-1);
	flags->min_width = ft_recalculate_flagnum(flags->min_width,
			ft_lstsize(flags->result));
	count = ft_print_type_with_align(flags);
	return (count);
}
