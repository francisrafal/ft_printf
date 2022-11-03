/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:56:21 by frafal            #+#    #+#             */
/*   Updated: 2022/11/03 18:22:36 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		print_hex(unsigned long long n, const char specifier);
int		print_str(char *str);
int		print_char(char c);
int		print_nbr(int n);
int		print_unsigned(unsigned int n);
char	*u_itoa(unsigned int n);

#endif
