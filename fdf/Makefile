# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/03 10:02:28 by jun               #+#    #+#              #
#    Updated: 2021/09/05 08:12:25 by jun              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
ifdef DEBUG
#	CFLAGS = -g3 -fsanitize=address
	CFLAGS = -g
else
	CFLAGS = -Wall -Wextra -Werror
endif

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

INC_DIR_MAN = ./includes/mandatory/
INC_DIR_BONUS = ./includes/bonus/

SRCS_MAN = $(addprefix $(SRCS_DIR), \
	   ft_atoi_basis.c\
	   ft_atoi_convert_base.c\
	   get_next_line_bonus.c\
	   get_next_line_utils_bonus.c\
	   get_data.c\
	   read_file.c\
	   projection.c\
	   draw_wireframe.c\
	   mlx_main.c\
	   Xiaolin_Wu_line_algo.c\
	   draw_line_utils.c\
	   main.c\
	   hook_fdf.c\
	   fdf_image_base.c\
	   )

SRCS_BONUS = $(addprefix $(SRCS_DIR_BONUS), \
	   ft_atoi_basis_bonus.c\
	   ft_atoi_convert_base_bonus.c\
	   get_next_line_bonus.c\
	   get_next_line_utils_bonus.c\
	   get_data_bonus.c\
	   read_file_bonus.c\
	   projection_bonus.c\
	   draw_wireframe_bonus.c\
	   mlx_main_bonus.c\
	   Xiaolin_Wu_line_algo_bonus.c\
	   draw_line_utils_bonus.c\
	   main_bonus.c\
	   hook_fdf_bonus.c\
	   fdf_image_base_bonus.c\
	   hook_mouse_bonus.c\
	   )

OBJS_MAN = ${SRCS_MAN:%.c=%.o}

OBJS_BONUS = ${SRCS_BONUS:%.c=%.o}

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS_BONUS)
else
	OBJ_FILES = $(OBJS_MAN)
endif

ifdef WITH_BONUS
	INC_DIR = $(INC_DIR_BONUS)
else
	INC_DIR = $(INC_DIR_MAN)
endif


.PHONY: all
all: $(LIBFT_FILE) $(MLX_FILE) $(OBJ_FILES) $(NAME)

$(NAME) : $(MLX_FILE) $(LIBFT_FILE) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT_FLAGS) $(MLX_FLAGS) -I$(INC_DIR) -o $@ 
	@install_name_tool -change $(MLX_LIB) $(MLX_FILE) $(NAME)

.PHONY: bonus
bonus:
	@make WITH_BONUS=1 $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I$(INC_DIR)  -c $< -o $@

$(LIBFT_FILE):
	@make -C $(LIBFT_DIR) bonus

$(MLX_FILE) :
	@make -C $(MLX_DIR)

.PHONY: clean
clean:
	rm -f $(OBJS_MAN) $(OBJS_BONUS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

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

.PHONY: re_bonus
re_bonus: fclean bonus

.PHONY: debug
debug: 
	@make DEBUG=1
