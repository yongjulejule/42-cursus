# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yongjule <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 16:23:07 by yongjule          #+#    #+#              #
#    Updated: 2021/07/31 16:42:42 by jun              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DFLAGS = -g3 -fsanitize=address
LFLAGS = -g
NAME = push_swap
LIB = libft/libft.a
SRCS_DIR = ./srcs/push_swap/
SRCS_DIR_BONUS = ./srcs/checker/
LIBDIR = libft
SRCS = $(addprefix $(SRCS_DIR), \
	   ft_split_once.c\
	   get_params.c\
	   libft_fuc_w_error.c\
	   push_swap_main.c\
	   str_to_int.c\
	   check_validity.c\
	   make_stack.c\
	   handle_dllst.c\
	   binary_search_tree.c\
	   operation_push_swap.c\
	   divide_and_merge_data.c\
	   sort_stack.c\
	   compress_operations.c\
	   joint_stack.c\
	   print_result.c\
	   radix_sort.c\
	   transfer_based_bits.c\
	   init_transfer.c\
	   transfer_b_to_a.c\
	   transfer_a_to_b.c\
	   )

SRCS_BONUS = $(addprefix $(SRCS_DIR_BONUS), \
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
	$(CC) $(DFLAGS) $(SRCS) $(LIB) srcs/push_swap/print_to_debug.c -o push_swap
	
bonusdebug: 
	$(CC) $(DFLAGS) $(SRCS_BONUS) $(LIB) -o push_swap

.PHONY: leakschk
leakschk:
	$(CC) $(LFLAGS) $(SRCS) $(LIB) -o push_swap
