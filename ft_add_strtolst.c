/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_strtolst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:32:42 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/08 18:30:38 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// void (*del)(void *)
// void	ft_lstadd_back(t_list **lst, t_list *new)

int	ft_add_strtolst(t_list **lst, char *s, void(*add_func)(t_list **, t_list *))
{
	t_list	*node;
	
	while (*s)
	{
		node = ft_lstnew(s++);
		if (!node)
			return (ft_lstclear(lst, &free), -1);
		add_func(lst, node);
	}
	return (0);
}
