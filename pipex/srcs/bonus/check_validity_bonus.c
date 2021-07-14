/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 03:37:17 by yongjule          #+#    #+#             */
/*   Updated: 2021/07/13 16:58:16 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/ft_pipex_bonus.h"

void	check_arg_validity(int argc, char **argv, char **envp)
{
	int	idx;

	idx = 1;
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
	while (idx < argc - 2)
	{
		argv[idx] = ft_strtrim(argv[idx], "\t\f\v\n\r ");
		idx++;
	}
}

static char	*prefix_dir_to_cmd(t_args *args, char *cmd, int nth_path)
{
	char		*tmpstr;
	char		*tmp_cmd;

	tmpstr = ft_strjoin_w_error(args->env_path[nth_path], "/");
	tmp_cmd = ft_strjoin_w_error(tmpstr, cmd);
	free(tmpstr);
	tmpstr = NULL;
	return (tmp_cmd);
}

void	check_cmd_validity(t_args *args, int cmd_idx, char *cmd)
{
	int			nth_path;
	char		*tmp_cmd;
	extern int	errno;

	nth_path = 0;
	while (args->env_path[nth_path] != NULL)
	{
		tmp_cmd = prefix_dir_to_cmd(args, cmd, nth_path);
		if (access(tmp_cmd, X_OK) == -1)
		{
			free(tmp_cmd);
			tmp_cmd = NULL;
		}
		else
		{
			free(cmd);
			cmd = NULL;
			args->params[cmd_idx][0] = tmp_cmd;
			return ;
		}
		nth_path++;
	}
	ft_putstr_fd(strerror(errno), 2);
	ft_putendl_fd(cmd, 2);
}
