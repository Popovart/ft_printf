/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_strtolst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:32:42 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/08 13:33:21 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_add_strtolst(t_list **lst, char *s)
{
	t_list	*node;

	while (*s)
	{
		node = ft_lstnew(s++);
		if (!node)
			return (ft_lstclear(lst, &free), 0);
		ft_lstadd_back(lst, node);
	}
	return (1);
}
