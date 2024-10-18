/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:33:55 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/18 12:36:39 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"

int	main(void)
{
	printf("%d\n", ft_printf("%s\n", "213"));
    printf("================\n");
    //printf("%d\n", printf("%-100..123s\n", "lol"));
	//printf("%d\n", printf("%c %d %-4s\n", 'c', 5, "lol"));
	// printf("%-0202.123d", 42);
	// printf("%- 4d\n", 10);
	// printf("%-4d\n", 10);
	// printf("%00d\n", 10);
	//printf("%d\n", ft_printf("% d\n", 5)); //OK
	//printf("%d\n", ft_printf("%- 3.2d\n", 5)); //OK
	//printf("%d\n", ft_printf("%-+2d\n", 5)); // OK
	//printf("%d\n", ft_printf("%- 142.132d\n", 5)); //OK
	//printf("%d\n", ft_printf("%142.132d\n", 5)); //OK
	//printf("%d\n", ft_printf("%0+2d\n", -5)); //OK
	//printf("================\n");
	//printf("%d\n", printf("% d\n", 5)); //OK
	//printf("%d\n", printf("%- 3.2d\n", 5)); //OK
	//printf("%d\n", printf("%0+2d\n", 5)); // OK
	//printf("%d\n", printf("%- 142.132d\n", 5)); //OK
	//printf("%d\n", printf("%142.132d\n", 5)); //OK
	//printf("%d\n", printf("%0+2d\n", -5)); //OK

	// strs
	// printf("%d\n", ft_printf("%12.12s %d\n", "lol", 12));
	//printf("================\n");

	// hex
	// printf("%d\n", ft_printf("%-10x\n", 12)); // ok
	//printf("================\n");
	// printf("%d\n", printf("%-10x\n", 12)); // ok

	// ptr
	//int x = 42;
	//printf("%d\n", ft_printf("%25p\n", (void *)&x));
	//printf("================\n");
	//printf("%d\n", printf("%25p\n", (void *)&x));
	//printf("%d\n", ft_printf("%5%"));
	//printf("\n================\n");
	//printf("%d\n", printf("%5%"));
	// i
	//printf("%d\n", ft_printf("%10.5i\n", -216)); // OK
	//printf("%d\n", ft_printf("%07i\n", -54)); // OK
	//printf("%d\n", ft_printf("%.0i\n", 0)); // OK
	//printf("%d\n", ft_printf("this %i number\n", -267)); //OK
	//printf("================\n");
	//printf("%d\n", printf("%10.5i\n", -216));
	//printf("%d\n", printf("%07i\n", -54));
	//printf("%d\n", printf("%.0i\n", 0));
	//printf("%d\n", printf("this %i number\n", -267));
	// u
	//printf("%d\n", ft_printf("%.0u\n", 0)); // OK
	//printf("================\n");
	//printf("%d\n", printf("%.0u\n", 0));

	// c
	// printf("%d\n", ft_printf("%-20c\n", 'x')); // OK
	// printf("%d\n", ft_printf("{%3c}", '\0')); // OK
	// printf("================\n");
	// printf("%d\n", printf("%-20c\n", 'x')); // OK
	// printf("%d\n", printf("{%3c}", '\0')); // OK

	// d
	// printf("%d\n", ft_printf("%%\n")); // OK
	// printf("================\n");
	// printf("%d\n", printf("%%\n")); // OK

	return (0);
}
