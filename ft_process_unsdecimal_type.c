/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_unsdecimal_type.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:46:17 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/18 14:05:10 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_process_unsdecimal_type(va_list args, t_flags *flags)
{
	int				count;
	unsigned int	ans_num;
	int				error;
	char			*num_str;

	error = 0;
	ans_num = va_arg(args, unsigned int);
	if (ans_num != 0 || flags->precision != 0)
	{
		num_str = ft_utoa(ans_num);
		if (!num_str)
			return (-1);
		error = ft_add_strtolst(&flags->result, num_str, &ft_lstadd_back);
		free(num_str);
		if (error == -1)
			return (-1);
	}
	count = ft_format_output_and_print(flags);
	return (count);
}
