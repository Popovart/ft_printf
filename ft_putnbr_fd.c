/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:28:52 by dmitrypopov       #+#    #+#             */
/*   Updated: 2024/10/05 14:47:01 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_rec_fd(int n, int fd)
{
	char	c;

	if (n <= 9)
	{
		c = n + '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_rec_fd(n / 10, fd);
		ft_putnbr_rec_fd(n % 10, fd);
	}
}

int	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	ft_putnbr_rec_fd(n, fd);
	return (ft_numlen(n));
}
