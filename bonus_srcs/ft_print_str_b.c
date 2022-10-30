/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 08:40:55 by abiru             #+#    #+#             */
/*   Updated: 2022/10/30 12:10:44 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	printn_char(const char *str, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		write(1, str + i, 1);
	return (i);
}

static void	printstr2(const char *str, t_flags *f, int *cc)
{
	if (f->width >= f->precision)
	{
		if (!f->minus && f->precision < (int)ft_strlen(str))
			*cc += ft_justify(' ', f->width - f->precision);
		else if (!f->minus && !(f->precision < (int)ft_strlen(str)))
			*cc += ft_justify(' ', f->width - (int)ft_strlen(str));
		if (f->precision < (int)ft_strlen(str))
			*cc += printn_char(str, f->precision);
		else
			*cc += printn_char(str, (int)ft_strlen(str));
		if (f->minus && f->precision < (int)ft_strlen(str))
			*cc += ft_justify(' ', f->width - f->precision);
		else if (f->minus && !(f->precision < (int)ft_strlen(str)))
			*cc += ft_justify(' ', f->width - (int)ft_strlen(str));
	}
	else if (f->width < f->precision && f->precision < (int)ft_strlen(str))
		*cc += printn_char(str, f->precision);
	else if (f->width < f->precision && !f->minus)
		*cc += ft_justify(' ', f->width - (int)ft_strlen(str));
	if (f->width < f->precision && !(f->precision < (int)ft_strlen(str)))
		*cc += printn_char(str, (int)ft_strlen(str));
	if (f->width < f->precision && f->minus)
		*cc += ft_justify(' ', f->width - (int)ft_strlen(str));
}

int	ft_print_str(const char *str, t_flags *f)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	if (!f->width && !f->dot)
		i += printn_char(str, (int)ft_strlen(str));
	else if (f->dot)
		printstr2(str, f, &i);
	else
	{
		if (!f->minus)
			i += ft_justify(' ', f->width - (int)ft_strlen(str));
		i += printn_char(str, (int)ft_strlen(str));
		if (f->minus)
			i += ft_justify(' ', f->width - (int)ft_strlen(str));
	}
	return (i);
}
