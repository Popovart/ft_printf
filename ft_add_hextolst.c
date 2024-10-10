/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_hextolst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrypopov <dmitrypopov@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:49:10 by dmitrypopov       #+#    #+#             */
/*   Updated: 2024/10/10 15:10:26 by dmitrypopov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_add_hextolst(t_list **lst, uintptr_t num, const int is_upper)
{
	char	*hex_base;
	t_list	*node;

	if (num == 0)
	{
		node = ft_lstnew(ft_strdup("0"));
		if (!node)
			return (ft_lstclear(lst, &free), -1);
		return (ft_lstadd_front(lst, node), 1);
	}
	if (is_upper)
		hex_base = "0123456789ABCDEF";
	else
		hex_base = "0123456789abcdef";
	while (num > 0)
	{
		node = ft_lstnew(ft_substr(hex_base, num % 16, 1));
		if (!node)
			return (ft_lstclear(lst, &free), -1);
		ft_lstadd_front(lst, node);
		num /= 16;
	}
	return (0);
}
