/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:59:34 by frafal            #+#    #+#             */
/*   Updated: 2022/11/01 16:15:26 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
// DELETE BEFORE SUBMISSION:
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		d;
	char	c;
	char	*s;
	size_t	i;

	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == 's')
		{
			s = va_arg(ap, char *);
			printf("string %s\n", s);
		}
		else if (format[i] == 'd')
		{
			d = va_arg(ap, int);
			printf("int %d\n", d);
		}
		else if (format[i] == 'c')
		{
			c = (char)va_arg(ap, int);
			printf("char %c\n", c);
		}
		i++;	
	}
	va_end(ap);
	// Allowed External Functions:
	// malloc, free, write, va_start, va_arg, va_copy, va_end 
	// Parse Variable Arguments
	// Parse Format String
	// Replace Format String with Variable Arguments
	// Print to Stdout
	// Count the Number of characters printed excluding null byte and return
	// Error should return negative value
	return (0);
}
