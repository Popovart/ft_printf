/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_string_type.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:27:52 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/18 13:00:00 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_process_string_type(va_list args, t_flags *flags)
{
	int		count;
	char	*str;

	str = va_arg(args, char *);
	if (flags->precision != -1)
	{
		str = ft_substr(str, 0, flags->precision);
		if (ft_add_strtolst(&flags->result, str, &ft_lstadd_back) == -1)
			return (-1);
	}
	else
	{
		if (ft_add_strtolst(&flags->result, ft_strdup(str), &ft_lstadd_back) ==
			-1)
			return (-1);
	}
	flags->min_width = ft_recalculate_flagnum(flags->min_width,
			ft_lstsize(flags->result));
	count = ft_print_type_with_align(flags);
	return (count);
}
