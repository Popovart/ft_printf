/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_decimal_type.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:12:22 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/18 14:19:16 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// here in case INT_MIN value won't change
int	ft_set_sign_and_revertnum(int neg_num, char **sign)
{
	*sign = "-";
	if (neg_num == -2147483648)
		return (-2147483648);
	return (neg_num * -1);
}

int	ft_process_decimal_type(va_list args, t_flags *flags)
{
	int		count;
	long	decimal_num;
	char	*num_str;
	int		error;

	decimal_num = va_arg(args, int);
	error = 0;
	if (decimal_num < 0)
		decimal_num = ft_set_sign_and_revertnum(decimal_num, &flags->sign);
	if (decimal_num != 0 || flags->precision != 0)
	{
		if (decimal_num == -2147483648)
			error = ft_add_strtolst(&flags->result, "2147483648",
					&ft_lstadd_back);
		else
		{
			num_str = ft_itoa(decimal_num);
			error = ft_add_strtolst(&flags->result, num_str, &ft_lstadd_back);
			free(num_str);
		}
		if (error == -1)
			return (-1);
	}
	count = ft_format_output_and_print(flags);
	return (count);
}
