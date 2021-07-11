/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:14:23 by jun               #+#    #+#             */
/*   Updated: 2021/07/11 19:49:35 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	split_opts(char *opts, t_args *args)
{
	int idx;
	int	len;

	idx = 0;
	if (*(opts + idx) == '\'')
	{
		len = (int)((opts + idx + 1) - ft_strchr((opts + idx),'\''));
		args->cmd_w_params[0][1] = ft_substr(opts, idx, len);
		len = idx;
	}
	else
	{
		len = (int)((opts + idx + 1) - ft_strchr((opts + idx),' '));
		args->cmd_w_params[0][1] = ft_substr(opts, idx, len);
		len = idx;
	}
}

void	get_params(char **argv, t_args *args)
{
	int	len;

	if (!ft_strchr(argv[2], '\''))
	{
		args->cmd_w_params[0] = ft_split(argv[2], ' ');
		if (!args->cmd_w_params[0])
		{
			perror("Error while get parameter");
			exit(EXIT_FAILURE);
		}
		return ;
	}
	len = (int)(ft_strchr(argv[2], ' ') - argv[2]);
	if (len < 0)
	{
		args->cmd_w_params[0][0] = ft_strdup(argv[2]); // 실패시 처리 해줘야함
		return ;
	}
	args->cmd_w_params[0][0] = ft_substr(argv[2], 0, len);
	split_opts(&argv[2][len + 1], args);
}

int main(int argc, char **argv)
{
	get_params(argv, NULL);
}
