/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_chartolst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:52:17 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/12 18:57:52 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_add_chartolst(t_list **lst, char c, void (*add_func)(t_list **,
			t_list *))
{
	t_list	*node;

	node = ft_lstnew(&c);
	if (!node)
		return (-1);
	add_func(lst, node);
	return (0);
}
