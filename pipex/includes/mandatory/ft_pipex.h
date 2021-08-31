/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:18:34 by yongjule          #+#    #+#             */
/*   Updated: 2021/08/30 14:15:30 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

/*
** Include Libraries
*/

# include <sys/errno.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "../libft.h"

/*
** User Defines
*/

# define PIPE_RD 0
# define PIPE_WR 1

typedef struct s_args
{
	int		argc;
	pid_t	stat;
	char	*file[2];
	char	**env_path;
	char	**envp;
	char	***params;
}	t_args;

/*
** Check Validity
*/

void	check_arg_validity(int argc, char **argv);
void	check_cmd_validity(t_args *args, int cmd_idx, char *cmd);
void	is_error(char *str_1, char *str_2);

/*
** Redirecting
*/

void	rdr_file_to_stdin(char *file);
void	rdr_stdout_to_file(char *file);
void	connect_pipe_fd(int *pipe_fd, int pipe_status);

/*
** Preprocessing
*/

void	build_structure(int argc, char **argv, char **envp, t_args *cmds);
void	get_params(char **argv, t_args *args);
void	breed_process(t_args *args);

/*
** Modified libft
*/

int		split_once(char *str, char *charset);
int		make_string(t_args *args, char *cmdset, int c_idx, int p_idx);
void	*ft_calloc_w_error(size_t count, size_t size);
char	*ft_substr_w_error(char const *s, unsigned int start, size_t len);
char	*ft_strjoin_w_error(char const *s1, char const *s2);

#endif
