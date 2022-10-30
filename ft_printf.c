/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:37:36 by abiru             #+#    #+#             */
/*   Updated: 2022/10/30 12:54:13 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printchar(int c)
{
	return (write(1, &c, 1));
}

static char	get_spec(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (c);
	return ('N');
}

static int	ft_printf_2(va_list args, char specifier)
{
	int	counter;

	counter = 0;
	if (specifier == 'c')
		counter += ft_printchar(va_arg(args, int));
	else if (specifier == 's')
		counter += ft_printstr(va_arg(args, const char *));
	else if (specifier == 'd' || specifier == 'i')
		counter += ft_putd_i(va_arg(args, int));
	else if (specifier == 'u')
		counter += ft_putnbr_u(va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		counter += ft_printhex(va_arg(args, unsigned int), specifier);
	else if (specifier == '%')
		counter += ft_printchar('%');
	else if (specifier == 'p')
		counter += ft_printptr(va_arg(args, unsigned long long));
	return (counter);
}

int	ft_printf(const char *s, ...)
{
	va_list			args;
	int				counter;
	int				i;

	i = -1;
	counter = 0;
	va_start(args, s);
	while (s[++i] != '\0' && s + i != NULL)
	{
		if (s[i] == '%')
		{
			if (get_spec(s[i + 1]) != 'N')
				counter += ft_printf_2(args, s[(i++) + 1]);
			else
				counter += ft_printchar(s[i]);
		}
		else
			counter += ft_printchar(s[i]);
	}
	va_end(args);
	return (counter);
}
