# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yongjule <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 16:23:07 by yongjule          #+#    #+#              #
#    Updated: 2021/08/24 17:25:39 by jun              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DFLAGS = -g3 -fsanitize=address
LFLAGS = -g
NAME = pipex
LIB = libft/libft.a
SRCS_DIR = ./srcs/mandatory/
SRCS_DIR_BONUS = ./srcs/bonus/
LIBDIR = libft
SRCS = $(addprefix $(SRCS_DIR), \
	   breed_process.c\
	   check_validity.c\
	   file_redirection.c\
	   get_params.c\
	   parse_commend.c\
	   pipex_main.c\
	   libft_fuc_w_error.c\
	   string_utils.c\
	   is_error.c\
	   )

SRCS_BONUS = $(addprefix $(SRCS_DIR_BONUS), \
	   breed_process_bonus.c\
	   check_validity_bonus.c\
	   file_redirection_bonus.c\
	   get_params_bonus.c\
	   parse_commend_bonus.c\
	   pipex_main_bonus.c\
	   libft_fuc_w_error_bonus.c\
	   handle_error_bonus.c\
	   string_utils_bonus.c\
	   get_next_line_bonus.c\
	   get_next_line_utils_bonus.c\
	   )

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS_BONUS)
else
	OBJ_FILES = $(OBJS)
endif

.PHONY: all
all: $(OBJ_FILES) $(NAME)

.PHONY: bonus
bonus: $(OBJ_FILES) $(NAME)
	@make WITH_BONUS=1 $(NAME)

$(NAME) : $(OBJ_FILES) $(LIB)
		$(CC) $(CFLAGS) $(OBJ_FILES) $(LIB) -o $@ 

$(LIB):
	make -C $(LIBDIR)

.PHONY: clean
clean:
	rm -f $(OBJS) $(OBJS_BONUS)
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

.PHONY: bonusdebug
bonusdebug: 
	$(CC) $(DFLAGS) $(SRCS_BONUS) $(LIB) -o pipex

.PHONY: leakschk
leakschk:
	$(CC) $(LFLAGS) $(SRCS) $(LIB) -o pipex
