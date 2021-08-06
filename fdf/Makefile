# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/03 10:02:28 by jun               #+#    #+#              #
#    Updated: 2021/08/06 17:45:42 by jun              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DFLAGS = -g3 -fsanitize=address
LFLAGS = -g

NAME = fdf

SRCS_DIR = ./srcs/mandatory/
SRCS_DIR_BONUS = ./srcs/bonus/

LIB_DIR = lib/

LIBFT_DIR = $(LIB_DIR)libft/
LIBFT_FLAGS = -L./$(LIBFT_DIR) -lft
LIBFT_FILE = $(LIBFT_DIR)libft.a

MLX_LIB = libmlx.dylib
MLX_DIR = $(LIB_DIR)mlx/
MLX_FLAGS = -L./$(MLX_DIR) -lmlx -framework OpenGl -framework Appkit
MLX_FILE = $(MLX_DIR)libmlx.dylib

INC_DIR = ./includes/

SRCS = $(addprefix $(SRCS_DIR), \
    ft_atoi_basis.c\
    ft_atoi_convert_base.c\
    get_next_line_bonus.c\
    get_next_line_utils_bonus.c\
    main.c\
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

%.o : %.c
	$(CC) $(CFLAGS) -I$(INC_DIR)  -c $< -o $@

.PHONY: all
all: $(LIBFT_FILE) $(MLX_FILE) $(OBJ_FILES) $(NAME)

.PHONY: bonus
bonus: $(OBJ_FILES) $(NAME)
	@make WITH_BONUS=1 $(NAME)

$(NAME) : $(MLX_FILE) $(LIBFT_FILE) $(OBJ_FILES)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $@ 
		@install_name_tool -change $(MLX_LIB) $(MLX_FILE) $(NAME)


$(LIBFT_FILE):
	@make -C $(LIBFT_DIR) bonus

$(MLX_FILE) :
	@make -C $(MLX_DIR)

.PHONY: clean
clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make -C $(LIBFT_DIR) clean

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean

.PHONY: ffclean
ffclean: clean
	rm -f $(NAME)
	rm -rf $(NAME).dSYM

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