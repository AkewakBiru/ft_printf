/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 08:41:33 by abiru             #+#    #+#             */
/*   Updated: 2022/10/30 12:10:47 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	init_flags(t_flags *flag)
{
	flag->dot = 0;
	flag->hash = 0;
	flag->space = 0;
	flag->plus = 0;
	flag->minus = 0;
	flag->zero = 0;
	flag->width = 0;
	flag->precision = 0;
	return ;
}

static int	ft_printf_2(va_list args, char specifier, t_flags *flag)
{
	int	counter;

	counter = 0;
	if (specifier == 'c')
		counter += ft_print_char(va_arg(args, int), flag);
	else if (specifier == 's')
		counter += ft_print_str(va_arg(args, const char *), flag);
	else if (specifier == 'd' || specifier == 'i')
		counter += ft_putdecimal(va_arg(args, int), flag);
	else if (specifier == 'u')
		counter += ft_putnbr_unsigned(va_arg(args, unsigned int), flag);
	else if (specifier == 'x' || specifier == 'X')
		counter += ft_printhex(va_arg(args, unsigned int), specifier, flag);
	else if (specifier == '%')
		counter += ft_print_per(flag);
	else if (specifier == 'p')
		counter += ft_print_ptr(va_arg(args, unsigned long long), flag);
	init_flags(flag);
	return (counter);
}

static void	clean_exit(va_list args, t_flags *flag)
{
	free(flag);
	va_end(args);
}

static t_flags	*printf_3(void)
{
	t_flags	*flag;

	flag = (t_flags *)malloc(sizeof(t_flags));
	if (!flag)
		flag = NULL;
	init_flags(flag);
	return (flag);
}

int	ft_printf(const char *s, ...)
{
	va_list			args;
	int				counter;
	int				i;
	t_flags			*flag;
	char			specifier;

	i = -1;
	counter = 0;
	va_start(args, s);
	flag = printf_3();
	while (s[++i] != '\0' && s + i != NULL)
	{
		if (s[i] == '%')
		{
			specifier = get_specifier(s + i + 1, 1);
			if (specifier != 'N' && set_flags(s, flag, &i))
				counter += ft_printf_2(args, specifier, flag);
		}
		else
			counter += ft_print_char(s[i], flag);
	}
	clean_exit(args, flag);
	return (counter);
}
