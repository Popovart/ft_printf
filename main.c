/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:33:55 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/06 20:48:33 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	//printf("%d\n", ft_printf("%c %d %-4s\n", 'c', 5, "lol"));
	//printf("================\n");
	// printf("%d\n", printf("%c %d %-4s\n", 'c', 5, "lol"));
	// printf("%-0202.123d", 42);
	// printf("%- 4d\n", 10);
	// printf("%-4d\n", 10);
	// printf("%00d\n", 10);
	printf("%d\n", ft_printf("% 10d\n", 25));
	printf("================\n");
	printf("%d\n", printf("% 10d\n", 25));
	return (0);
}

// ft_printf("word %d text", 10);
