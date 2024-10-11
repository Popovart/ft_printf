/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:34:12 by dmitrii           #+#    #+#             */
/*   Updated: 2024/09/24 15:54:14 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = 0;
	while (dlen < dsize && dst[dlen])
		dlen++;
	slen = 0;
	while (src[slen])
		slen++;
	if (dlen == dsize)
		return (dlen + slen);
	i = 0;
	while (src[i] && (dlen + i + 1) < dsize)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	if ((dlen + i) < dsize)
		dst[dlen + i] = '\0';
	return (dlen + slen);
}
