/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_hex_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:25:17 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/08 16:36:37 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_add_hextolst(t_list **lst, unsigned int num, const int is_upper)
{
	char	*hex_base;
	t_list	*node;

	if (num == 0)
	{
		node = ft_lstnew(ft_strdup("0"));
		if (!node)
			return (ft_lstclear(lst, &free), -1);
		return (ft_lstadd_front(lst, node), 1);
	}
	if (is_upper)
		hex_base = "0123456789ABCDEF";
	else
		hex_base = "0123456789abcdef";
	while (num > 0)
	{
		node = ft_lstnew(ft_substr(hex_base, num % 16, 1));
		if (!node)
			return (ft_lstclear(lst, &free), -1);
		ft_lstadd_front(lst, node);
		num /= 16;
	}
	return (0);
}

// нужно перетащить часть кода в отдельные функции, а то там одна и таже логика
int	ft_process_hex_type(va_list args, t_flags *flags, const int is_upper)
{
	int		count;
	int		num;
    
	num = va_arg(args, unsigned int);
	if (ft_add_hextolst(&flags->result, num, is_upper) == -1)
		return (-1);
	if (flags->hash_flag)
	{
		if (is_upper)
			flags->sign = "X0";
		else
			flags->sign = "x0";
	}
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
