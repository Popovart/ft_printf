/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_signtolst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:23:34 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/18 11:32:58 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_add_signtolst(t_list **lst, char *sign)
{
	return (ft_add_strtolst(lst, ft_strdup(sign), &ft_lstadd_front));
}
