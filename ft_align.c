/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:16:45 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/08 13:17:19 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_align(char c, int min_width)
{
	int	count;

	count = 0;
	while (min_width-- > 0)
	{
		write(1, &c, 1);
		count++;
	}
	return (count);
}
