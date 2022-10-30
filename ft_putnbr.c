/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:31:54 by abiru             #+#    #+#             */
/*   Updated: 2022/10/30 12:11:48 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		ft_printstr("2147483648");
		return ;
	}
	if (nbr < 0)
		nbr *= -1;
	if (nbr >= 0 && nbr <= 9)
	{
		ft_putchar_fd(nbr + '0', 1);
		return ;
	}
	else
		ft_putnbr(nbr / 10);
	ft_putnbr(nbr % 10);
}
