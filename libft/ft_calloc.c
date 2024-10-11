/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:29:13 by dmitrii           #+#    #+#             */
/*   Updated: 2024/09/24 15:53:32 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*dest;

	if (nmemb != 0 && size != 0 && nmemb > ((size_t)(-1)) / size)
		return (NULL);
	dest = (void *)malloc(size * nmemb);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < (size * nmemb))
	{
		dest[i] = 0;
		i++;
	}
	return ((void *)dest);
}
