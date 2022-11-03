/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:23:04 by frafal            #+#    #+#             */
/*   Updated: 2022/11/03 18:34:06 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int	main(void)
{
	int	val;

	val = 0;
	val = ft_printf("String: \"%s\"\n", "This is a string.");
	printf("Return Value: %d\n", val);
	val = ft_printf("Decimal: %d\n", 123456);
	printf("Return Value: %d\n", val);
	val = ft_printf(" %d \n", 0);
	printf("Return Value: %d\n", val);
	val = ft_printf("Negative Decimal: %d\n", -123456);
	printf("Return Value: %d\n", val);
	val = ft_printf("Character: %c\n", 'a');
	printf("Return Value: %d\n", val);
	val = ft_printf("Just one simple string.\n");
	printf("Return Value: %d\n", val);
	val = ft_printf("Hex: %x\n", 2147483647);
	printf("Return Value: %d\n", val);
	printf("/////\n");
	val = printf("printf Pointer: %p\n", NULL);
	printf("Return Value: %d\n", val);
	val = ft_printf("ft_printf Pointer: %p\n", NULL);
	printf("Return Value: %d\n", val);
	val = printf("printf: %%y\n");
	printf("Return Value: %d\n", val);
	val = printf("ft_printf: %%y\n");
	printf("Return Value: %d\n", val);
	return (0);
}
