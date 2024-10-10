/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:02:38 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/10 21:05:52 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_unsnumlen(unsigned int n)
{
	unsigned int	len;

	len = 1;
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char			*str;
	unsigned int	len;
	unsigned int	nb;

	nb = n;
	len = ft_unsnumlen(nb);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
		return (str[0] = '0', str);
	while (len > 0 && nb >= 10)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	str[--len] = nb + '0';
	return (str);
}
