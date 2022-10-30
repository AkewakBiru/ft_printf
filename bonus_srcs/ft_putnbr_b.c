/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 08:43:03 by abiru             #+#    #+#             */
/*   Updated: 2022/10/30 12:11:01 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putnbr_b(int nbr, t_flags *flag)
{
	if (nbr == -2147483648)
	{
		ft_print_str("2147483648", flag);
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
		ft_putnbr_b(nbr / 10, flag);
	ft_putnbr_b(nbr % 10, flag);
}
