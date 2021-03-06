/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 03:37:17 by yongjule          #+#    #+#             */
/*   Updated: 2021/08/28 12:52:48 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/ft_pipex.h"

void	check_arg_validity(int argc, char **argv)
{
	int	idx;

	idx = 1;
	if (argc != 5)
	{
		ft_putendl_fd("Check Number of Arguments", 2);
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
}
