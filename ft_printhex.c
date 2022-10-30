/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:11:56 by abiru             #+#    #+#             */
/*   Updated: 2022/10/30 12:11:36 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printhex2(long nbr, char *hex_set)
{
	if (nbr >= 0 && nbr < 16)
	{
		write(1, &hex_set[nbr % 16], 1);
		return ;
	}
	else
		ft_printhex2(nbr / 16, hex_set);
	ft_printhex2(nbr % 16, hex_set);
}

int	ft_printhex(unsigned int nbr, char specifier)
{
	unsigned int	val;

	val = nbr;
	if ((int)val < 0)
		val = 4294967296 + val;
	if (specifier == 'x')
		ft_printhex2(val, "0123456789abcdef");
	else
		ft_printhex2(val, "0123456789ABCDEF");
	return (ft_digit_ctr(val, 16));
}
