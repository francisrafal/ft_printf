/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:59:34 by frafal            #+#    #+#             */
/*   Updated: 2022/11/03 12:13:24 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
// DELETE BEFORE SUBMISSION:
#include <stdio.h>

static int	print_str(char *str)
{
	int	printed;

	printed = 0;
	while (str[printed])
	{
		ft_putchar_fd(str[printed], 1);
		printed++;
	}
	return (printed);
}

static int	print_nbr(int n)
{
	int		printed;
	char	*a;

	printed = 0;
	a = ft_itoa(n);
	printed += print_str(a);
	free(a);
	return (printed);
}

static int	print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

static int	parse_specifier(const char specifier, va_list ap)
{
	int	printed;	

	printed = 0;
	if (specifier == 's')
		printed += print_str(va_arg(ap, char *));
	else if (specifier == 'd')
		printed += print_nbr(va_arg(ap, int));
	else if (specifier == 'i')
		printed += print_nbr(va_arg(ap, int));
	else if (specifier == 'c')
		printed += print_char(va_arg(ap, int));
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
			printed += print_char(format[i]);
		if (format[i] == '%')
			printed += parse_specifier(format[++i], ap);	
		i++;
	}
	va_end(ap);

	// Allowed External Functions:
	// malloc, free, write, va_start, va_arg, va_copy, va_end 
	// Parse Format String
	// Count the Number of characters printed excluding null byte and return
	// Error should return negative value
	// %p The void * pointer argument has to be printed in hexadecimal format.
	// %u Prints an unsigned decimal (base 10) number.
	// %x Prints a number in hexadecimal (base 16) lowercase format.
	// %X Prints a number in hexadecimal (base 16) uppercase format.
	// %% Prints a percent sign
	// Merge To Master Branch
	return (printed);
}
