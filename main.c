/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:33:55 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/12 18:46:45 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	//printf("%d\n", ft_printf("%c %d %-4ss\n", 'c', 5, "lol"));
	//printf("================\n");
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
	//printf("%d\n", ft_printf("%12.12s %d\n", "lol", 12)); 
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
	

	// printf("%d\n", ft_printf("%100.12s\n", "lol kek cheburek puk muk lol"));
	// printf("================\n");
	// printf("%d\n", printf("%c %d %s %u %% %-100p\n", 'c', 5, "lol", -200, NULL));

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


	// chaos tests KO
	//printf("%d\n", ft_printf("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c//%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c\n", ' ','!','"','#','$', '%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':', ';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q', 'R','S','T','U', 'V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p', 'q','r','s','t','u','v','w','x','y','z','{','|','~')); // OK
	//printf("================\n");
	//printf("%d\n", printf("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c//%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c\n", ' ','!','"','#','$', '%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':', ';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q', 'R','S','T','U', 'V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p', 'q','r','s','t','u','v','w','x','y','z','{','|','~'));


	// c
	//printf("%d\n", ft_printf("%-20c\n", 'x'));
	printf("%d\n", ft_printf("{%3c}", '\0'));
	printf("================\n");
	// printf("%d\n", printf("%-20c\n", 'x'));
	printf("%d\n", printf("{%3c}", '\0'));
	
	return (0);
}

// ft_printf("word %d text", 10);
