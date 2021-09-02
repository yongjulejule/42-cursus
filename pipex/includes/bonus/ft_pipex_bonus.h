/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:18:34 by yongjule          #+#    #+#             */
/*   Updated: 2021/09/02 14:21:42 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_BONUS_H
# define FT_PIPEX_BONUS_H

/*Include Libraries*/

# include <sys/errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft.h"
# include "get_next_line_bonus.h"

/*User Defines*/

# define PIPE_RD 0
# define PIPE_WR 1
# define X_ERR 126
# define CMD_ERR 127
# define E_ACCESS 13
# define E_NOCMD 2

typedef struct s_args
{
	int		argc;
	int		is_heredoc;
	char	*limiter;
	char	*file[2];
	char	**env_path;
	char	**envp;
	char	***params;
	pid_t	*pid;
	int		**pipe_fd;
}	t_args;

/*FUNCTIONS*/

/*Check Validity*/

void	is_error(char *str_1, char *str_2, int exit_status);
void	check_arg_validity(int argc, char **argv);
void	check_cmd_validity(t_args *args, int cmd_idx, char *cmd);

/*Redirecting*/

void	rdr_file_to_stdin(char *file, t_args *args);
void	rdr_stdout_to_file(char *file, t_args *args);
void	connect_pipe_fd(int *pipe_fd, int pipe_status);
void	destroy_pipe(int *pipe_fd);

/*Preprocessing*/

void	build_structure(int argc, char **argv, char **envp, t_args *cmds);
void	get_params(char **argv, t_args *args);
void	breed_process(t_args *args);

/*
** Handle exit code
*/

int		wstatus(int status);
int		wifexited(int status);
int		wifsignaled(int status);
int		wexitstatus(int status);
int		wtermsig(int status);
void	wait_process(t_args *args);

/*Utils*/

int		split_once(char *str, char *charset);
int		make_string(t_args *args, char *cmdset, int c_idx, int p_idx);
void	*ft_calloc_w_error(size_t count, size_t size);
char	*ft_substr_w_error(char const *s, unsigned int start, size_t len);
char	*ft_strjoin_w_error(char const *s1, char const *s2);

#endif
