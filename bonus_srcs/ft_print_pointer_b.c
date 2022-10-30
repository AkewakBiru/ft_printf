/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:11:29 by abiru             #+#    #+#             */
/*   Updated: 2022/10/30 12:10:41 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	dig_count(unsigned long long p, t_flags *f)
{
	int	i;

	i = 0;
	if (!p && f->dot)
		return (0);
	else if (!p && !f->dot)
		return (1);
	if (p == 0)
		return (1);
	while (p > 0)
	{
		p /= 16;
		i++;
	}
	return (i);
}

static void	printer(unsigned long long p)
{
	if (p < 16)
	{
		write(1, &"0123456789abcdef"[p % 16], 1);
		return ;
	}
	else
		printer(p / 16);
	printer(p % 16);
}

static int	print_ptr2(unsigned long long val, t_flags *f)
{
	write(1, "0x", 2);
	if (!val && f->dot)
		return (2);
	if (val == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	else
		printer(val);
	return (2 + dig_count(val, f));
}

int	ft_print_ptr(unsigned long long val, t_flags *flag)
{
	int	cc;

	cc = 0;
	if (flag->minus)
	{
		cc += print_ptr2(val, flag);
		cc += ft_justify(' ', flag->width - dig_count(val, flag) - 2);
	}
	else
	{
		cc += ft_justify(' ', flag->width - dig_count(val, flag) - 2);
		cc += print_ptr2(val, flag);
	}
	return (cc);
}
