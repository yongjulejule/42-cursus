CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = ft_memset.c\
	   ft_memcpy.c\
	   ft_bzero.c\
	   ft_memccpy.c\
	   ft_memchr.c\
	   ft_memmove.c\
	   ft_memcmp.c\
	   ft_strlen.c\
	   ft_atoi.c\
	   ft_strlcpy.c\
	   ft_strchr.c\
	   ft_strrchr.c\
	   ft_strnstr.c\
	   ft_strncmp.c\
	   ft_isalpha.c\
	   ft_isdigit.c\
	   ft_isalnum.c\
	   ft_isascii.c\
	   ft_isprint.c\
	   ft_toupper.c\
	   ft_tolower.c\
	   ft_calloc.c\
	   ft_strdup.c\
	   ft_substr.c\
	   ft_strjoin.c\
	   ft_strtrim.c\
	   ft_split.c\
	   ft_itoa.c\
	   ft_strmapi.c\
	   ft_putchar_fd.c\
	   ft_putstr_fd.c\
	   ft_putendl_fd.c\
	   ft_putnbr_fd.c\
	   ft_strlcat.c

OBJS = ${SRCS:.c=.o}

BONUS_SRCS = ${SRCS}\
			 ft_lstnew.c\
			 ft_lstadd_front.c\
			 ft_lstsize.c\
			 ft_lstlast.c\
			 ft_lstadd_back.c\
			 ft_lstdelone.c\
			 ft_lstclear.c\
			 ft_lstiter.c\
			 ft_lstmap.c\

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

.PHONY: all
all: $(NAME)

$(NAME) : $(OBJS) $(BONUS_OBJS)
	ar rc $@ $(OBJS) $(BONUS_OBJS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(BONUS_OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

#.PHONY: bonus
#bonus: $(BONUS_OBJS)
#	ar cr $(NAME) $(BONUS_OBJS)
