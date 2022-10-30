/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbruns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:07:29 by abiru             #+#    #+#             */
/*   Updated: 2022/10/30 12:11:51 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_un(unsigned int nbr)
{
	if ((int)nbr >= 0 && nbr <= 9)
	{
		ft_putchar_fd(nbr + '0', 1);
		return ;
	}
	else
		ft_putnbr(nbr / 10);
	ft_putnbr(nbr % 10);
}

int	ft_putnbr_u(int nbr)
{
	unsigned int	val;

	val = nbr;
	if ((int)val < 0)
		val = 4294967296 + val;
	ft_putnbr_un(val);
	return (ft_digit_ctr(val, 10));
}
