/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:43:22 by abiru             #+#    #+#             */
/*   Updated: 2022/10/30 12:11:39 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(const char *str)
{
	int	i;

	i = -1;
	if (!str)
		str = "(null)";
	while (str && str[++i] != '\0')
		write(1, str + i, 1);
	return ((int)ft_strlen(str));
}
