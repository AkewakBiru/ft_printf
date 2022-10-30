/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 08:42:54 by abiru             #+#    #+#             */
/*   Updated: 2022/10/30 12:11:04 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_putnbr_uns(unsigned int nbr, t_flags *flag)
{
	if ((int)nbr >= 0 && nbr <= 9)
	{
		ft_putchar_fd(nbr + '0', 1);
		return ;
	}
	else
		ft_putnbr_b(nbr / 10, flag);
	ft_putnbr_b(nbr % 10, flag);
}

static void	check_wp(t_flags *f, int *cc, unsigned int nbr)
{
	if (f->precision < ft_digit_ctr(nbr, 10))
		f->precision = ft_digit_ctr(nbr, 10);
	if (f->precision < f->width && !f->minus)
		*cc += ft_justify(' ', f->width - f->precision);
	*cc += ft_justify('0', f->precision - ft_digit_ctr(nbr, 10));
	ft_putnbr_uns(nbr, f);
	if (f->minus)
		*cc += ft_justify(' ', f->width - f->precision);
}

int	ft_putnbr_unsigned(int nbr, t_flags *f)
{
	unsigned int	val;
	int				char_count;

	val = nbr;
	if ((int)val < 0)
		val = 4294967296 + val;
	char_count = ft_digit_ctr(val, 10);
	if (f->dot)
	{
		if (f->precision == 0 && nbr == 0)
			char_count += ft_justify(' ', f->width) - 1;
		else
			check_wp(f, &char_count, nbr);
	}
	else if (f->zero)
		char_count += ft_justify('0', f->width - ft_digit_ctr(val, 10));
	else if (!(f->minus || f->zero))
		char_count += ft_justify(' ', f->width - ft_digit_ctr(val, 10));
	if (!f->dot)
		ft_putnbr_uns(val, f);
	if (!f->dot && f->minus)
		char_count += ft_justify(' ', f->width - ft_digit_ctr(val, 10));
	return (char_count);
}
