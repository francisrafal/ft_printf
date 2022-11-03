/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:00:50 by frafal            #+#    #+#             */
/*   Updated: 2022/11/03 15:58:23 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	contains_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

int	contains_double(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_printnbr(unsigned long nbr, char *base)
{
	char	c;
	int		b;

	b = ft_strlen(base);
	if (nbr == 0)
		return ;
	ft_printnbr(nbr / b, base);
	c = base[nbr % b];
	write(1, &c, 1);
}

void	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned long	abs_val;

	abs_val = nbr;
	if (ft_strlen(base) < 2 || contains_sign(base) || contains_double(base))
		return ;
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	if (nbr < 0)
	{
		abs_val = (-1) * abs_val;
		write(1, "-", 1);
	}
	ft_printnbr(abs_val, base);
}
