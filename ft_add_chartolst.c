/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_chartolst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:52:17 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/18 12:46:18 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// I need to allocate memory here
int	ft_add_chartolst(t_list **lst, char c, void (*add_func)(t_list **,
			t_list *))
{
	char	*content;
	t_list	*new_node;

	content = malloc(sizeof(char) * 2);
	if (!content)
		return (-1);
	content[0] = c;
	content[1] = '\0';
	new_node = ft_lstnew(content);
	if (!new_node)
		return (-1);
	add_func(lst, new_node);
	return (0);
}
