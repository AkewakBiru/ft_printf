/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdecimal_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 08:42:44 by abiru             #+#    #+#             */
/*   Updated: 2022/10/30 12:10:58 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_digit_ctr2(long nbr, int base)
{
	int	counter;

	counter = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
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

static int	calc_padding_amt(t_flags *flag, int nbr)
{
	int	i;

	i = ft_digit_ctr(nbr, 10);
	if (nbr > 0 && flag->plus)
		i++;
	if ((flag->space && nbr > 0 && !flag->plus) || (flag->space && nbr < 0
			&& !flag->minus))
		i++;
	return (i);
}

static void	check_wp(t_flags *f, int *cc, int nbr)
{
	if (f->precision < ft_digit_ctr2(nbr, 10))
		f->precision = ft_digit_ctr2(nbr, 10);
	if (f->precision < f->width && nbr < 0 && !f->minus)
		*cc += ft_justify(' ', f->width - f->precision - 1);
	else if (f->precision < f->width && nbr >= 0 && !f->minus)
		*cc += ft_justify(' ', f->width - f->precision - f->plus);
	if ((f->precision < f->width && nbr < 0) || (!(f->precision < f->width)
			&& nbr < 0 && !f->minus && !f->zero))
		write(1, "-", 1);
	else if (f->precision < f->width && f->plus && nbr >= 0 && !f->zero)
		*cc += write(1, "+", 1);
	if (f->precision < f->width)
		*cc += ft_justify('0', f->precision - ft_digit_ctr2(nbr, 10));
	else if (!(f->precision < f->width) && f->plus && nbr >= 0 && !f->zero)
		*cc += write(1, "+", 1);
	if (!(f->precision < f->width))
		*cc += ft_justify('0', f->precision - ft_digit_ctr2(nbr, 10));
	ft_putnbr_b(nbr, f);
	if (nbr >= 0 && f->minus)
		*cc += ft_justify(' ', f->width - f->precision - f->plus);
	else if (nbr < 0 && f->minus && f->precision < f->width)
		*cc += ft_justify(' ', f->width - f->precision - 1);
}

static void	ft_putdecimal2(int nbr, t_flags *flag, int *cc)
{
	if ((flag->minus || flag->zero) && nbr < 0)
		write(1, "-", 1);
	if (flag->zero && !flag->minus)
		*cc += ft_justify('0', flag->width - calc_padding_amt(flag, nbr));
	else if (!flag->minus)
		*cc += ft_justify(' ', flag->width - calc_padding_amt(flag, nbr)
				- flag->space);
	if (nbr < 0 && !flag->zero && !flag->minus)
		write(1, "-", 1);
	else if (flag->plus && nbr >= 0 && !flag->zero)
		*cc += write(1, "+", 1);
	ft_putnbr_b(nbr, flag);
	if (flag->minus)
		*cc += ft_justify(' ', flag->width - *cc);
	if (flag->width >= *cc)
		*cc += flag->width - *cc;
}

int	ft_putdecimal(int nbr, t_flags *flag)
{
	int	char_count;

	char_count = ft_digit_ctr(nbr, 10);
	if (nbr < 0 && (flag->zero || flag->minus)
		&& flag->precision >= flag->width)
		write(1, "-", 1);
	else if (nbr >= 0 && flag->plus && flag->zero)
		char_count += write(1, "+", 1);
	if (flag->space && nbr >= 0 && !flag->plus)
		char_count += write(1, " ", 1);
	if (flag->dot)
	{
		if (flag->precision == 0 && nbr == 0)
			char_count += ft_justify(' ', flag->width) - 1;
		else
			check_wp(flag, &char_count, nbr);
	}
	else
		ft_putdecimal2(nbr, flag, &char_count);
	return (char_count);
}
