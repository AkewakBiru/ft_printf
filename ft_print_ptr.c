/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:17:17 by abiru             #+#    #+#             */
/*   Updated: 2022/10/30 12:11:26 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dig_count(unsigned long long p)
{
	int	i;

	i = 0;
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

static int	print_ptr2(unsigned long long val)
{
	write(1, "0x", 2);
	if (val == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	else
		printer(val);
	return (2 + dig_count(val));
}

int	ft_printptr(unsigned long long val)
{
	int	cc;

	cc = 0;
	cc += print_ptr2(val);
	return (cc);
}
