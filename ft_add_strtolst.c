/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_strtolst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:32:42 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/18 15:17:08 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_add_strtolst(t_list **lst, char *s, void (*add_func)(t_list **,
			t_list *))
{
	t_list	*node;
	char	*str;

	while (*s)
	{
		str = malloc(2 * sizeof(char));
		if (!str)
			return (-1);
		str[0] = *s;
		str[1] = '\0';
		node = ft_lstnew(str);
		if (!node)
		{
			return (-1);
		}
		add_func(lst, node);
		s++;
	}
	return (0);
}
