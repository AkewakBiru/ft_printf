/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_justify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:13:27 by abiru             #+#    #+#             */
/*   Updated: 2022/10/29 18:16:25 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_justify(char c, int size)
{
	int	temp;

	temp = size;
	if (size <= 0)
		return (0);
	while (size > 0)
	{
		ft_putchar_fd(c, 1);
		size--;
	}
	return (temp);
}
