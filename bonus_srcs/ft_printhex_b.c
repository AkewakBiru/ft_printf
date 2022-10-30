/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 08:42:22 by abiru             #+#    #+#             */
/*   Updated: 2022/10/30 12:10:53 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_printhex2(long nbr, char *hex_set)
{
	if (nbr >= 0 && nbr < 16)
	{
		write(1, &hex_set[nbr % 16], 1);
		return ;
	}
	else
		ft_printhex2(nbr / 16, hex_set);
	ft_printhex2(nbr % 16, hex_set);
}

static int	write_hex(char specifier)
{
	if (specifier == 'x')
		return (write(1, "0x", 2));
	else
		return (write(1, "0X", 2));
}

static int	printhex_wp(unsigned int *val, char specifier, t_flags *f, int *cc)
{
	if (f->width <= f->precision && f->hash)
		*cc += write_hex(specifier);
	if (f->width <= f->precision)
		*cc += ft_justify('0', f->precision - ft_digit_ctr(*val, 16));
	if (f->width > f->precision && ((!f->minus && !f->zero && !f->hash)
			|| (!f->hash && !f->minus)))
		*cc += ft_justify(' ', f->width - f->precision);
	if (f->width > f->precision && ((!f->minus && !f->zero && f->hash)
			|| (f->hash && !f->minus)))
		*cc += ft_justify(' ', f->width - f->precision - 2);
	if (f->width > f->precision && f->hash)
		*cc += write_hex(specifier);
	if (f->width > f->precision && (f->precision > ft_digit_ctr(*val, 16)))
		*cc += ft_justify('0', f->precision - ft_digit_ctr(*val, 16));
	if (specifier == 'x')
		ft_printhex2(*val, "0123456789abcdef");
	else
		ft_printhex2(*val, "0123456789ABCDEF");
	if (f->width > f->precision && (f->minus && !f->hash))
		*cc += ft_justify(' ', f->width - f->precision);
	if (f->width > f->precision && (f->minus && f->hash))
		*cc += ft_justify(' ', f->width - f->precision - 2);
	return (*cc);
}

static int	printhex_w(unsigned int val, char specifier, t_flags *f, int *cc)
{
	if (f->dot)
		return (printhex_wp(&val, specifier, f, cc));
	if (f->width > ft_digit_ctr(val, 16) && f->zero && !f->hash)
		*cc += ft_justify('0', f->width - ft_digit_ctr(val, 16));
	if (f->width > ft_digit_ctr(val, 16) && !f->minus && !f->zero && !f->hash)
		*cc += ft_justify(' ', f->width - ft_digit_ctr(val, 16));
	if (f->width > ft_digit_ctr(val, 16) && f->zero && f->hash)
		*cc += ft_justify('0', f->width - ft_digit_ctr(val, 16) - 2);
	if (f->width > ft_digit_ctr(val, 16) && !f->minus && !f->zero && f->hash)
		*cc += ft_justify(' ', f->width - ft_digit_ctr(val, 16) - 2);
	if (f->hash && !f->minus && !f->zero)
		*cc += write_hex(specifier);
	if (specifier == 'x')
		ft_printhex2(val, "0123456789abcdef");
	else
		ft_printhex2(val, "0123456789ABCDEF");
	if (f->width > ft_digit_ctr(val, 16) && f->minus && !f->zero && f->hash)
		*cc += ft_justify(' ', f->width - ft_digit_ctr(val, 16) - 2);
	if (f->width > ft_digit_ctr(val, 16) && f->minus && !f->zero && !f->hash)
		*cc += ft_justify(' ', f->width - ft_digit_ctr(val, 16));
	return (*cc);
}

int	ft_printhex(unsigned int nbr, char specifier, t_flags *f)
{
	unsigned int	val;
	int				char_count;

	val = nbr;
	if ((int)val < 0)
		val = 4294967296 + val;
	if (val == 0)
		f->hash = 0;
	char_count = ft_digit_ctr(val, 16);
	if (f->hash && !f->dot && (f->minus || f->zero))
		char_count += write_hex(specifier);
	if (f->dot && f->precision == 0 && nbr == 0)
	{
		char_count += ft_justify(' ', f->width) - 1;
		return (char_count);
	}
	if (f->precision < ft_digit_ctr(val, 16))
		f->precision = ft_digit_ctr(val, 16);
	printhex_w(nbr, specifier, f, &char_count);
	return (char_count);
}
