/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:16:00 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/08 15:20:54 by dmitrii          ###   ########.fr       */
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

void	print_flags(t_flags *flags)
{
	printf("Flags structure:\n");
	printf("minus_flag: %d\n", flags->minus_flag);
	printf("zero_flag: %d\n", flags->zero_flag);
	printf("min_width: %d\n", flags->min_width);
	printf("sign: %s\n", flags->sign ? flags->sign : "N");
	printf("precision: %d\n", flags->precision);
	printf("hash_flag: %d\n", flags->hash_flag);
	printf("result list\n");
	fflush(stdout);
	ft_lstiter(flags->result, ft_putlstchar);
	printf("lst size: %d\n", ft_lstsize(flags->result));
	printf("\n");
}

void	ft_process_flags(char **fmt_ptr, t_flags *flags, int *shift)
{
	while (ft_isflag(**fmt_ptr))
	{
		if (**fmt_ptr == '-' && !flags->minus_flag)
			flags->minus_flag = 1;
		else if (**fmt_ptr == '0' && !flags->minus_flag && !flags->zero_flag)
			flags->zero_flag = 1;
		else if (**fmt_ptr == '+' && flags->sign[0] != '+')
			flags->sign = "+";
		else if (**fmt_ptr == ' ' && !flags->sign)
			flags->sign = " ";
		else if (**fmt_ptr == '#')
			flags->hash_flag = 1;
		(*fmt_ptr)++;
		(*shift)++;
	}
}

int	ft_recalculate_flagnum(int flagnum, const int num_len)
{
	if (flagnum > num_len)
		flagnum -= num_len;
	else
		flagnum = 0;
	return (flagnum);
}
