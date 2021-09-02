/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commend_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:36:00 by jun               #+#    #+#             */
/*   Updated: 2021/09/02 14:23:31 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/ft_pipex_bonus.h"

static void	allocate_pipe_memory(t_args *args)
{
	int	cnt;

	cnt = 0;
	args->pipe_fd = (int **)ft_calloc_w_error(args->argc - 4, sizeof(int *));
	while (cnt < args->argc - 4)
	{
		args->pipe_fd[cnt] = (int *)ft_calloc_w_error(2, sizeof(int));
		cnt++;
	}
}

static void	init_structure(int argc, char **argv, t_args *args)
{
	if (!ft_memcmp(argv[1], "here_doc", ft_strlen("here_doc") + 1))
	{
		if (argc < 6)
			is_error("pipex: ", "check arguments in heredoc", EXIT_FAILURE);
		args->is_heredoc = 1;
		args->limiter = argv[2];
		args->file[0] = ft_strdup(".tmp.here_doc");
		if (!(args->file[0]))
			is_error("pipex: ", "error in malloc", EXIT_FAILURE);
	}
	else
	{
		args->is_heredoc = 0;
		args->file[0] = argv[1];
	}
	args->file[1] = argv[argc - 1];
	args->params = (char ***)ft_calloc_w_error(argc - 2, sizeof(char **));
	args->params[argc - 2 - 1] = NULL;
	args->argc = argc;
	args->pid = (pid_t *)ft_calloc_w_error(argc - 3, sizeof(pid_t));
}

static	void	get_path(char **envp, t_args *args)
{
	int	env_str_idx;

	env_str_idx = 0;
	while (envp[env_str_idx])
	{
		if (!ft_strncmp("PATH=", envp[env_str_idx], 5))
			break ;
		env_str_idx++;
	}
	if (envp[env_str_idx] == NULL)
		is_error("pipex: ", "path envp not found", EXIT_FAILURE);
	args->env_path = ft_split(&envp[env_str_idx][5], ':');
	if (args->env_path == NULL)
		is_error("pipex: ", "error while split", EXIT_FAILURE);
}

void	make_cmds(t_args *args)
{
	int	cmd_idx;

	cmd_idx = 0;
	while (args->params[cmd_idx] != NULL)
	{
		check_cmd_validity(args, cmd_idx, args->params[cmd_idx][0]);
		cmd_idx++;
	}
}

void	build_structure(int argc, char **argv, char **envp, t_args *args)
{
	int	cmd_idx;

	cmd_idx = 2;
	init_structure(argc, argv, args);
	get_path(envp, args);
	get_params(argv, args);
	make_cmds(args);
	if (args->is_heredoc)
		args->argc--;
	allocate_pipe_memory(args);
}
