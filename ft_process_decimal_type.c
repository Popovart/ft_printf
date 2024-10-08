/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_decimal_type.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:12:22 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/08 13:53:56 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_add_signtolst(t_list **lst, const char sign)
{
	t_list	*node;

	if (sign)
	{
		if (sign == '+')
			node = ft_lstnew(ft_strdup("+"));
		else if (sign == ' ')
			node = ft_lstnew(ft_strdup(" "));
		else if (sign == '-')
			node = ft_lstnew(ft_strdup("-"));
		if (!node)
			return (ft_lstclear(lst, &free), 0);
		ft_lstadd_front(lst, node);
	}
	return (1);
}

int	ft_add_zerosandsigntolst(t_list **lst, int flagnum, const char sign)
{
	t_list	*node;
	int		lst_len;

	lst_len = ft_lstsize(*lst);
	if (sign == '-')
		lst_len++;
	flagnum = ft_recalculate_flagnum(flagnum, lst_len);
	while (flagnum-- > 0)
	{
		node = ft_lstnew(ft_strdup("0"));
		if (!node)
			return (ft_lstclear(lst, &free), 0);
		ft_lstadd_front(lst, node);
	}
	if (!ft_add_signtolst(lst, sign))
		return (0);
	return (1);
}

// I need to handle when I receive
//	-1 in ft_add_zerosandsigntolst and ft_add_zerosandsigntolst,
//	but now I omit it
int	ft_process_decimal_type(va_list args, t_flags *flags)
{
	int		count;
	long	decimal_num;

	decimal_num = va_arg(args, int);
	if (decimal_num < 0)
	{
		flags->sign = '-';
		decimal_num *= -1;
	}
	ft_add_strtolst(&flags->result, ft_itoa(decimal_num));
	if (flags->precision != -1)
		ft_add_zerosandsigntolst(&flags->result, flags->precision, flags->sign);
	else if (flags->zero_flag)
	{
		ft_add_zerosandsigntolst(&flags->result, flags->min_width, flags->sign);
		flags->min_width = 0;
	}
	else
		ft_add_signtolst(&flags->result, flags->sign);
	flags->min_width = ft_recalculate_flagnum(flags->min_width,
			ft_lstsize(flags->result));
	count = ft_print_type_with_align(flags);
	return (count);
}
