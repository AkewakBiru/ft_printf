/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 08:41:43 by abiru             #+#    #+#             */
/*   Updated: 2022/10/30 12:44:28 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);
int		ft_putd_i(int nbr);
int		ft_printstr(const char *str);
int		ft_putnbr_u(int nbr);
void	ft_putnbr(int nbr);
int		ft_printhex(unsigned int nbr, char specifier);
int		ft_printptr(unsigned long long val);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *str);
int		ft_digit_ctr(long nbr, int base);
#endif
