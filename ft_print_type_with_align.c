/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_with_align.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:53:21 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/08 13:54:05 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_type_with_align(t_flags *flags)
{
	int	count;

	count = ft_lstsize(flags->result);
	if (flags->minus_flag)
	{
		ft_lstiter(flags->result, ft_putlstchar);
		count += ft_align(' ', flags->min_width);
	}
	else
	{
		count += ft_align(' ', flags->min_width);
		ft_lstiter(flags->result, ft_putlstchar);
	}
	return (count);
}
