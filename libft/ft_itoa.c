/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrypopov <dmitrypopov@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:29:15 by dmitrypopov       #+#    #+#             */
/*   Updated: 2024/09/25 23:45:16 by dmitrypopov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = n;
	len = ft_numlen(nb);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
		return (str[0] = '0', str);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (len > 0 && nb >= 10)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	str[--len] = nb + '0';
	return (str);
}

// int	main(void)
// {
// 	char	*result;

// 	result = ft_itoa(0);
// 	printf("Result: %s\n", result);
// 	free(result);

// 	result = ft_itoa(-12345);
// 	printf("Result: %s\n", result);
// 	free(result);

// 	result = ft_itoa(42);
// 	printf("Result: %s\n", result);
// 	free(result);

// 	result = ft_itoa(-2147483648);
// 	printf("Result: %s\n", result);
// 	free(result);

// 	return (0);
// }