/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:36:00 by jun               #+#    #+#             */
/*   Updated: 2021/09/01 11:33:30 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/ft_pipex.h"

static	void	init_structure(int argc, char **argv, t_args *args)
{
	args->params = (char ***)ft_calloc_w_error(argc - 2, sizeof(char **));
	args->params[argc - 2 - 1] = NULL;
	args->pid = (pid_t *)ft_calloc_w_error(argc - 3, sizeof(pid_t));
	args->argc = argc;
	args->file[0] = argv[1];
	args->file[1] = argv[argc - 1];
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
}
