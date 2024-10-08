/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:17:57 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/08 13:18:12 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_extract_num(char **fmt_ptr, int *shift)
{
	int	flag_num;

	flag_num = 0;
	while (ft_isdigit(**fmt_ptr))
	{
		flag_num = flag_num * 10 + (**fmt_ptr - '0');
		(*shift)++;
		(*fmt_ptr)++;
	}
	return (flag_num);
}
