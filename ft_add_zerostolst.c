/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_zerostolst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:24:23 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/11 18:52:44 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_add_zerostolst(t_list **lst, int flagnum, char *sign)
{
	t_list	*node;
	int		lst_len;
	
	lst_len = ft_lstsize(*lst);
	if (sign[0] == '-')
		lst_len++;
	flagnum = ft_recalculate_flagnum(flagnum, lst_len);
	while (flagnum-- > 0)
	{
		node = ft_lstnew(ft_strdup("0"));
		if (!node)
			return (-1);
		ft_lstadd_front(lst, node);
	}
	return (0);
}
