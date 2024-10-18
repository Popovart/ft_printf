/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_string_type.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:27:52 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/18 16:15:53 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_setnull(char *str)
{
	if (!str)
		return ("(null)");
	return (str);
}

// this function redundantly allocate str
// I did this in order to free str in
// all cases later
char	*ft_process_str_prec(int precision, char *str)
{
	if (precision != -1)
	{
		if (!str && precision < 6)
			precision = 0;
		str = ft_substr(ft_setnull(str), 0, precision);
		return (str);
	}
	return (ft_strdup(ft_setnull(str)));
}

int	ft_process_string_type(va_list args, t_flags *flags)
{
	int		count;
	char	*str;
	int		error;

	error = 0;
	str = va_arg(args, char *);
	str = ft_process_str_prec(flags->precision, str);
	error = ft_add_strtolst(&flags->result, str, &ft_lstadd_back);
	free(str);
	if (error == -1)
		return (-1);
	flags->min_width = ft_recalculate_flagnum(flags->min_width,
			ft_lstsize(flags->result));
	count = ft_print_type_with_align(flags);
	return (count);
}
