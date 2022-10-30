/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:03:46 by abiru             #+#    #+#             */
/*   Updated: 2022/10/30 12:11:14 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_getwidth_prec(const char *str, t_flags *flag)
{
	const char	*tmp;

	tmp = str;
	tmp--;
	if (!flag->width)
	{
		while (ft_isdigit(*tmp) && *tmp != '\0' && *tmp != '%')
			tmp--;
		flag->width = ft_atoi(++tmp);
	}
	flag->precision = ft_atoi(++str);
	flag->dot = 1;
}

static int	get_next_char(const char *s, const char c)
{
	int	i;

	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	return (i);
}

static void	set_flags2(const char c, t_flags *flag)
{
	if (c == '#')
		flag->hash = 1;
	else if (c == '+')
		flag->plus = 1;
	else if (c == ' ')
		flag->space = 1;
	else if (c == '-')
		flag->minus = 1;
	else if (c == '0' && !flag->dot)
		flag->zero = 1;
}

int	set_flags(const char *str, t_flags *flag, int *j)
{
	int	i;

	i = ++(*j);
	while (str[i] != '\0' && get_specifier(str + i, 0) == 'N')
	{
		set_flags2(str[i], flag);
		if (str[i] == '.')
		{
			ft_getwidth_prec(str + i, flag);
			if (ft_isdigit(str[i + 1]))
				i += ft_digit_ctr(flag->precision, 10) - 1;
		}
		else if (ft_isdigit(str[i]) && flag->width == 0 && flag->dot == 0)
		{
			flag->width = ft_atoi(str + i);
			i += ft_digit_ctr(flag->width, 10) - 1;
		}
		i += get_next_char(str + i + 1, str[i]) + 1;
	}
	*j = i;
	return (i + 1);
}
