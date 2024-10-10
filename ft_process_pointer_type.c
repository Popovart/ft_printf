/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_pointer_type.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrypopov <dmitrypopov@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:48:12 by dmitrypopov       #+#    #+#             */
/*   Updated: 2024/10/10 15:01:03 by dmitrypopov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_process_pointer_type(va_list args, t_flags *flags)
{
	int		count;
	void	*ptr;

	ptr = va_arg(args, void *);
	if (ft_add_hextolst(&flags->result, (uintptr_t)ptr, 0) == -1)
		return (-1);
	flags->sign = "x0";
	count = ft_format_output_and_print(flags);
	return (count);
}
