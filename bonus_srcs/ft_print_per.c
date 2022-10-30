/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_per.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:57:10 by abiru             #+#    #+#             */
/*   Updated: 2022/10/30 12:10:38 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_per(t_flags *flag)
{
	int	cc;

	cc = 0;
	if (!flag->minus && !flag->zero)
		cc += ft_justify(' ', flag->width - 1);
	if (!flag->minus && flag->zero)
		cc += ft_justify('0', flag->width - 1);
	cc += write(1, "%", 1);
	if (flag->minus)
		cc += ft_justify(' ', flag->width - 1);
	return (cc);
}
