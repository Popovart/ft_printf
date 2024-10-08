/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:33:55 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/08 16:43:53 by dmitrii          ###   ########.fr       */
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
	//printf("%d\n", ft_printf("%-+2d\n", 5)); // OK
	printf("%d\n", ft_printf("%- 142.132d\n", 5)); //NEOK
	//printf("%d\n", ft_printf("%142.132d\n", 5)); //OK
	//printf("%d\n", ft_printf("%0+2d\n", -5)); //OK
	printf("================\n");
	//printf("%d\n", printf("%0+2d\n", 5)); // OK
	printf("%d\n", printf("%- 142.132d\n", 5)); //NEOK
	//printf("%d\n", printf("%142.132d\n", 5)); //OK
	//printf("%d\n", printf("%0+2d\n", -5)); //OK

	// strs
	// printf("%d\n", ft_printf("%12.12s %d\n", "lol", 12)); 
	//printf("================\n");

	// hex
	//printf("%d\n", ft_printf("%#x\n", 12)); 
	//printf("================\n");
	//printf("%d\n", printf("%#x\n", 12)); 
	return (0);
}

// ft_printf("word %d text", 10);
