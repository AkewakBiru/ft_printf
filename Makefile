# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 18:02:46 by abiru             #+#    #+#              #
#    Updated: 2022/10/30 12:19:01 by abiru            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_printstr.c ft_strlen.c ft_putnbr.c \
		ft_putd_i.c ft_putnbruns.c ft_digit_ctr.c \
		ft_printhex.c ft_print_ptr.c ft_putchar_fd.c \

BONUS_DIR = ./bonus_srcs

BONUS_OBJS_DIR = ./b_objs

BONUS_SRCS = ft_printf_b.c ft_print_char.c ft_print_str_b.c ft_justify.c get_specifier.c \
		ft_putdecimal_b.c ft_putnbr_unsigned_b.c ft_putnbr_b.c ft_digit_ctr.c \
		ft_printhex_b.c ft_print_pointer_b.c ft_atoi.c ft_putchar_fd.c \
		ft_strlen.c set_flags.c ft_isdigit.c ft_print_per.c

CC = gcc

CFLAGS = -Wextra -Werror -Wall

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:%.c=$(BONUS_OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: create_dir $(BONUS_OBJS)
	rm -rf *.a
	ar -rcs $(NAME) $(BONUS_OBJS)

$(BONUS_OBJS_DIR)/%.o:$(BONUS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

create_dir:
	@mkdir -p $(BONUS_OBJS_DIR)

clean:
	rm -rf *.o
	rm -rf $(BONUS_OBJS_DIR)/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
