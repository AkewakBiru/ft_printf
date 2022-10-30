/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putd_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:56:29 by abiru             #+#    #+#             */
/*   Updated: 2022/10/30 12:11:45 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putd_i2(int nbr)
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
		ft_putd_i2(nbr / 10);
	ft_putd_i2(nbr % 10);
}

int	ft_putd_i(int nbr)
{
	int	char_count;

	char_count = ft_digit_ctr(nbr, 10);
	if (nbr < 0)
		write(1, "-", 1);
	ft_putd_i2(nbr);
	return (char_count);
}
