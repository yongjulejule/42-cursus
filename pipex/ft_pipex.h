/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:18:34 by yongjule          #+#    #+#             */
/*   Updated: 2021/07/09 15:03:36 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h> //perror
#include <string.h> //strerror
#include "ft_pipex.h"
#include "libft/libft.h"

#define PIPE_RD 0
#define PIPE_WR 1
void	check_arg_validity(int argc, char **argv, char **envp);
void	rdr_file_to_stdin(char *file);
void	rdr_stdout_to_file(char *file);
extern int errno;
#endif
