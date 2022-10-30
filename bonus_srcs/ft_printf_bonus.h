/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:02:27 by abiru             #+#    #+#             */
/*   Updated: 2022/10/30 12:10:50 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct flags
{
	int	hash;
	int	space;
	int	plus;
	int	dot;
	int	minus;
	int	zero;
	int	width;
	int	precision;
}		t_flags;

int		ft_printf(const char *s, ...);
int		ft_printhex(unsigned int nbr, char specifier, t_flags *f);
int		ft_putdecimal(int nbr, t_flags *flag);
int		ft_putnbr_unsigned(int nbr, t_flags *flag);
void	ft_putnbr_b(int nbr, t_flags *flag);
int		ft_print_str(const char *str, t_flags *flag);
int		ft_print_char(int c, t_flags *flag);
int		ft_print_ptr(unsigned long long val, t_flags *flag);
int		ft_print_per(t_flags *flag);
int		ft_digit_ctr(long nbr, int base);
char	get_specifier(const char *s, int i);
int		ft_justify(char c, int size);
int		set_flags(const char *str, t_flags *flag, int *j);
int		ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *str);
int		ft_isdigit(int arg);
#endif