/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:36:00 by jun               #+#    #+#             */
/*   Updated: 2021/07/11 16:57:40 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static	void	allocate_structure(int argc, char **argv, t_args *args)
{
	args = (t_args *)malloc(sizeof(t_args));
	if (!args)
	{
		perror("Malloc Error while initiate structure");
		exit(EXIT_FAILURE);
	}
	args->cmd_w_params = (char ***)malloc(sizeof(char **) * (argc - 3));
	if (!args->cmd_w_params)
	{
		free(args);
		perror("Malloc Error while initiate structure Params");
		exit(EXIT_FAILURE);
	}
	args->cmd_w_params[argc - 3 - 1] = NULL;
}

static	void	init_structure(int argc, char **argv, t_args *args)
{
	allocate_structure(argc, argv, args);
	args->argc = argc;
	args->file[0] = argv[1];
	args->file[1] = argv[argc - 1];
}

static	void	get_path(char **envp, t_args *args)
{
	int env_str_idx;

	env_str_idx = 0;
	while (envp[env_str_idx])
	{
		if (!ft_strncmp("PATH=", envp[env_str_idx], 5))
			break ;
		env_str_idx++;
	}
	if (envp[env_str_idx] == NULL)
	{
		ft_putendl_fd("PATH EVNP not found", 2);
		exit(EXIT_FAILURE);
	}
	args->env_path = ft_split(&envp[env_str_idx][5], ':');
	if (args->env_path == NULL)
	{
		perror("Error_while_split");
		exit(EXIT_FAILURE);
	}
}

static	void	make_cmds(char *cmd, t_args *args)
{
	int	nth_path;
	char	*tmp_cmd;

	nth_path = 0;
	tmp_cmd = ft_strjoin(args->env_path[nth_path], cmd);
	if (!tmp_cmd)
	{
		perror("Error while strjoin");
		exit(EXIT_FAILURE);
	}
}

void	build_structure(int argc, char **argv, char **envp, t_args *args)
{
	int	cmd_idx;

	cmd_idx = 2;
	init_structure(argc, argv, args);
	get_path(envp, args);
	get_params(argv, args);
	while (cmd_idx < argc - 1)
		make_cmds(argv[cmd_idx++], args);
	check_cmd_validity(args);
}
