/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 03:37:17 by yongjule          #+#    #+#             */
/*   Updated: 2021/07/12 20:45:16 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	check_arg_validity(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_putendl_fd("Check Number of Arguments", 2);
		exit(EXIT_FAILURE);
	}
	if (!argv)
	{
		ft_putendl_fd("Argument Value Error", 2);
		exit(EXIT_FAILURE);
	}
	if (!envp)
	{
		ft_putendl_fd("Envp Error", 2);
		exit(EXIT_FAILURE);
	}
}

void	check_cmd_validity(t_args *args, int cmd_idx, char *cmd)
{
	int	nth_path;
	char	*tmp_cmd;
	char	*tmpstr;

	nth_path = 0;
	while (args->env_path[nth_path] != NULL)
	{
		tmpstr = ft_strjoin_w_error(args->env_path[nth_path], "/");
		tmp_cmd = ft_strjoin_w_error(tmpstr, cmd);
		free(tmpstr);
		tmpstr = NULL;
		if (access(tmp_cmd, X_OK) == -1)
		{
			free(tmp_cmd);
			tmp_cmd = NULL;
		}
		else
		{
			free(cmd);
			cmd = NULL;
			args->cmd_w_params[cmd_idx][0] = tmp_cmd;
			return ;
		}
		nth_path++;
	}
	ft_putstr_fd(strerror(errno), 2);
	ft_putendl_fd(cmd, 2);
}
