/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:59:34 by frafal            #+#    #+#             */
/*   Updated: 2022/11/03 11:21:04 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
// DELETE BEFORE SUBMISSION:
#include <stdio.h>

static int	parse_specifier(const char specifier, va_list ap)
{
	int		printed;	

	printed = 0;
	if (specifier == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	else if (specifier == 'd')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (specifier == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	// Calculate printed characters
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	int		printed;	

	va_start(ap, format);
	printed = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			printed++;
		}
		if (format[i] == '%')
		{
			i++;
			printed += parse_specifier(format[i], ap);	
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
	// %c Prints a single character.
	// %s Prints a string (as defined by the common C convention).
	// %p The void * pointer argument has to be printed in hexadecimal format.
	// %d Prints a decimal (base 10) number.
	// %i Prints an integer in base 10.
	// %u Prints an unsigned decimal (base 10) number.
	// %x Prints a number in hexadecimal (base 16) lowercase format.
	// %X Prints a number in hexadecimal (base 16) uppercase format.
	// %% Prints a percent sign
	// Merge To Master Branch
	return (printed);
}
