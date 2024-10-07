/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:22:29 by dmitrypopov       #+#    #+#             */
/*   Updated: 2024/10/07 16:16:09 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_node;

	while (*lst != NULL)
	{
		temp_node = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(temp_node, del);
	}
}
