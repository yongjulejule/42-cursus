# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yongjule <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 16:23:07 by yongjule          #+#    #+#              #
#    Updated: 2021/07/08 16:55:12 by yongjule         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DFLAGS = -g3 -fsanitize=address
LFLAGS = -g
NAME = pipex
LIB = libft/libft.a
LIBDIR = libft
SRCS = \
	   pipex_main.c\
	   check_validity.c\
	   file_redirection.c\
#		parse_commend.c\

OBJS = ${SRCS:.c=.o}

BONUS_SRCS = ${SRCS}\

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

.PHONY: all
all: $(NAME)

.PHONY: bonus
bonus: $(NAME) 

$(NAME) : $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $@ 

$(LIB):
	make -C $(LIBDIR)

.PHONY: clean
clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C $(LIBDIR) clean

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	make -C $(LIBDIR) fclean

.PHONY: ffclean
ffclean: clean
	rm -f $(NAME)
	rm -rf $(NAME).dSYM
	make -C $(LIBDIR) fclean

.PHONY: re
re: fclean all

.PHONY: debug
debug: 
	$(CC) $(DFLAGS) $(SRCS) $(LIB) -o pipex

.PHONY: leakschk
leakschk: clean
	$(CC) $(LFLAGS) $(OBJS) $(LIB) -o pipex
