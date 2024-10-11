/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_precision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrypopov <dmitrypopov@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:21:21 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/11 15:17:40 by dmitrypopov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_process_precision(char **fmt_ptr, int *zero_flag, int *shift)
{
	int	precision;
	
	(*fmt_ptr)++;
	(*shift)++;
	precision = ft_extract_num(fmt_ptr, shift);
	*zero_flag = 0;
	return (precision);
}
