/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_strtolst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:32:42 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/18 12:31:38 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_add_strtolst(t_list **lst, char *s, void (*add_func)(t_list **,
			t_list *))
{
	t_list	*node;

	while (*s)
	{
		node = ft_lstnew(s++);
		if (!node)
			return (-1);
		add_func(lst, node);
	}
	return (0);
}
