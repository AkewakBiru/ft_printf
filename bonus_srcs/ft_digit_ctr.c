/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_ctr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 08:42:09 by abiru             #+#    #+#             */
/*   Updated: 2022/10/29 18:48:30 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_digit_ctr(long nbr, int base)
{
	int	counter;

	counter = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		counter++;
		if (nbr == -2147483648)
			nbr++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		nbr /= base;
		counter++;
	}
	return (counter);
}
