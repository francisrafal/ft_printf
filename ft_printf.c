/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:59:34 by frafal            #+#    #+#             */
/*   Updated: 2022/11/03 16:30:38 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	print_str(char *str)
{
	int	printed;

	printed = 0;
	if (str == NULL)
		return (print_str("(null)"));
	while (str[printed])
	{
		ft_putchar_fd(str[printed], 1);
		printed++;
	}
	return (printed);
}

static char	*u_itoa(unsigned int n)
{
	char			*a;
	int				digits;
	unsigned int	num;

	num = n;
	digits = 1;
	while (num / 10 != 0)
	{
		digits++;
		num /= 10;
	}
	a = (char *)malloc((digits + 1) * sizeof(char));
	if (a == NULL)
		return (NULL);
	a[digits] = '\0';
	while (digits > 0)
	{
		a[digits - 1] = n % 10 + '0';
		digits--;
		n /= 10;
	}
	return (a);
}

static int	print_unsigned(unsigned int n)
{
	int		printed;
	char	*a;

	printed = 0;
	a = u_itoa(n);
	printed += print_str(a);
	free(a);
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

static int	print_hex(unsigned long long n, const char specifier)
{
	int		printed;

	printed = 0;
	if (specifier == 'x')
		printed += ft_putnbr_base(n, "0123456789abcdef");
	if (specifier == 'X')
		printed += ft_putnbr_base(n, "0123456789ABCDEF");
	if (specifier == 'p')
	{
		if (n == 0)
		{
			printed += print_str("(nil)");
			return (printed);
		}
		printed += print_str("0x");
		printed += ft_putnbr_base(n, "0123456789abcdef");
	}
	return (printed);
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
	else if (specifier == 'u')
		printed += print_unsigned(va_arg(ap, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		printed += print_hex(va_arg(ap, unsigned int), specifier);
	else if (specifier == 'p')
		printed += print_hex(va_arg(ap, unsigned long long), 'p');
	else if (specifier == '%')
		printed += print_char('%');
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
	// %x Prints a number in hexadecimal (base 16) lowercase format.
	// %X Prints a number in hexadecimal (base 16) uppercase format.
	// %SOMETHING ELSE (Should Print the something else)
	// Merge To Master Branch
	return (printed);
}
