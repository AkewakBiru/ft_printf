/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 08:41:12 by abiru             #+#    #+#             */
/*   Updated: 2022/10/30 12:10:35 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_char(int c, t_flags *flag)
{
	int	cc;

	cc = 0;
	if (!flag->minus)
		cc += ft_justify(' ', flag->width - 1);
	cc += write(1, &c, 1);
	if (flag->minus)
		cc += ft_justify(' ', flag->width - 1);
	return (cc);
}
