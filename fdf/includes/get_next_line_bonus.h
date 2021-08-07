/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:21:17 by yongjule          #+#    #+#             */
/*   Updated: 2021/08/07 14:17:52 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define ERROR_FLAG 0
# define SUCCESS_FLAG 1
# define NOT_ALLOCED 2

# include <unistd.h>
# include <stdlib.h>

typedef struct s_file
{
	int				size;
	int				fd;
	int				nl;
	char			*text;
	struct s_file	*next;
}	t_file;

int				get_next_line(int fd, char **line);
int				find_fd(t_file **root, t_file **cur, char **line, int fd);
int				re_alloc(t_file *cur, int size);
char			*mysubstr(char *s, int start, int len);
int				free_lst(t_file **root, t_file **cur, char **line, int flag);
t_file			*init_fd(int fd);

#endif
