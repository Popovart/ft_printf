/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:16:00 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/18 11:11:01 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isflag(char c)
{
	if (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#')
		return (1);
	return (0);
}

void	init_flags(t_flags *flags)
{
	flags->minus_flag = 0;
	flags->zero_flag = 0;
	flags->min_width = -1;
	flags->sign = "\0";
	flags->precision = -1;
	flags->hash_flag = 0;
	flags->result = NULL;
}

int	ft_isflagrepeat(char c, const t_flags *flags)
{
	if (c == '-' && flags->minus_flag)
		return (-1);
	if (c == '0' && flags->zero_flag)
		return (-1);
	if ((c == '+' || c == ' ') && flags->sign[0])
		return (-1);
	if (c == '#' && flags->hash_flag)
		return (-1);
	return (0);
}

int	ft_process_flags(char **fmt_ptr, t_flags *flags, int *shift)
{
	while (ft_isflag(**fmt_ptr))
	{
		if (ft_isflagrepeat(**fmt_ptr, flags) == -1)
			return (-1);
		if (**fmt_ptr == '-' && !flags->minus_flag)
			flags->minus_flag = 1;
		else if (**fmt_ptr == '0' && !flags->minus_flag && !flags->zero_flag)
			flags->zero_flag = 1;
		else if (**fmt_ptr == '+' && flags->sign[0] != '+')
			flags->sign = "+";
		else if (**fmt_ptr == ' ' && !*flags->sign)
			flags->sign = " ";
		else if (**fmt_ptr == '#' && !flags->hash_flag)
			flags->hash_flag = 1;
		(*fmt_ptr)++;
		(*shift)++;
	}
	return (0);
}

int	ft_recalculate_flagnum(int flagnum, const int num_len)
{
	if (flagnum > num_len)
		flagnum -= num_len;
	else
		flagnum = 0;
	return (flagnum);
}
