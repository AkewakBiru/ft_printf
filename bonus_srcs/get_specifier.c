/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:42:02 by abiru             #+#    #+#             */
/*   Updated: 2022/10/30 12:11:12 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	is_specifier(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (c);
	return ('N');
}

char	get_specifier(const char *s, int j)
{
	int	i;

	i = 0;
	if (j == 0)
	{
		if (is_specifier(*s) != 'N')
			return ((char)*s);
	}
	else
	{
		while (s[i])
		{
			if (is_specifier(s[i]) != 'N')
				return ((char)s[i]);
			i++;
		}
	}
	return ('N');
}
