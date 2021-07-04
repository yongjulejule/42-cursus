# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yongjule <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/24 10:57:47 by yongjule          #+#    #+#              #
#    Updated: 2021/06/24 11:15:05 by yongjule         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIB = libft/libft.a
LIBDIR = libft
SRCS = \
	   ft_printf.c\
	   ft_print_str.c\
	   ft_print_width.c\
	   ft_print_char.c\
	   ft_print_deci.c\
	   ft_print_deci_nbr.c\
	   ft_print_sign.c\
	   get_flags.c\
	   get_asterisk_info.c\
	   get_nbr_len.c\
	   get_length_flag.c\
	   ft_putnbr_char_fd.c\
	   ft_putnbr_l_fd.c\
	   ft_putnbr_ll_fd.c\
	   ft_putnbr_short_fd.c\
	   ft_putnbr_uchar_fd.c\
	   ft_putnbr_ui_fd.c\
	   ft_putnbr_ul_fd.c\
	   ft_putnbr_ull_fd.c\
	   ft_putnbr_ushort_fd.c\
	   ft_putnbr_abs_fd.c\
	   ft_putstr_uft_fd.c\
	   go_print.c\
	   lsts.c\
	   parse.c\
	   ft_utflen.c\
	   ft_print_hash.c\
	   ft_print_hexa.c\
	   ft_print_hexa_nbr.c\
	   ft_putnbr_uchar_hexa_fd.c\
	   ft_putnbr_ui_hexa_fd.c\
	   ft_putnbr_ul_hexa_fd.c\
	   ft_putnbr_ull_hexa_fd.c\
	   ft_putnbr_ushort_hexa_fd.c\
	   ft_handle_n_spec.c\
	   get_byte.c\
	   ft_split_for_pf.c\
	   is_zero.c\

OBJS = ${SRCS:.c=.o}

BONUS_SRCS = ${SRCS}\

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

.PHONY: all
all: $(NAME)

.PHONY: bonus
bonus: $(NAME) 

$(NAME) : $(OBJS) $(LIB)
	ar rc $@ $(OBJS) 

$(LIB):
	make -C $(LIBDIR)
	cp $(LIB) $(NAME)

.PHONY: clean
clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C $(LIBDIR) clean

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	make -C $(LIBDIR) fclean

.PHONY: re
re: fclean all

.PHONY: debug
debug: all 
	$(CC) -g3 -fsanitize=address $(MAIN) $(NAME) $(LIB)
	./a.out

.PHONY: leakschk
leakschk: clean
	$(CC) -g $(MAIN) $(NAME) $(LIB)
