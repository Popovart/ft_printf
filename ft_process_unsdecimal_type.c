/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_unsdecimal_type.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:46:17 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/11 19:09:33 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_process_unsdecimal_type(va_list args, t_flags *flags)
{
	int				count;
	unsigned int	ans_num;

	ans_num = va_arg(args, unsigned int);
	if (ft_add_strtolst(&flags->result, ft_utoa(ans_num), &ft_lstadd_back))
		return (-1);
	count = ft_format_output_and_print(flags);
	return (count);
}
