/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:14:23 by jun               #+#    #+#             */
/*   Updated: 2021/07/21 17:23:44 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/ft_pipex_bonus.h"

static	int	count_params(char *cmdset)
{
	int	size;
	int	start;
	int	len;

	start = 0;
	size = 0;
	while (cmdset[start] != '\0')
	{
		size++;
		while (is_charset(cmdset[start], "\t\n\v\f\r "))
			start++;
		if (is_charset(cmdset[start], "'"))
			len = split_once(&cmdset[start], "'") + start + 1;
		else if (is_charset(cmdset[start], "\""))
			len = split_once(&cmdset[start], "\"") + start + 1;
		else
			len = split_once(&cmdset[start], "\t\n\v\f\r ") + start;
		start = len;
	}
	return (size);
}

static	void	parse_param(t_args *args, char *cmdset, int c_idx, int p_idx)
{
	int	start;
	int	len;
	int	size;

	size = count_params(cmdset);
	start = 0;
	while (p_idx < size)
	{
		while (is_charset(cmdset[start], "\t\n\v\f\r "))
			start++;
		len = make_string(args, &cmdset[start], c_idx, p_idx);
		start = len + start + 1;
		p_idx++;
	}
}

static	void	get_each_params(char *cmdset, int cmd_idx, t_args *args)
{
	int	param_idx;
	int	size;

	param_idx = 0;
	size = count_params(cmdset);
	args->params[cmd_idx]
		= (char **)ft_calloc_w_error(sizeof(char *), size + 1);
	parse_param(args, cmdset, cmd_idx, param_idx);
}

void	get_params(char **argv, t_args *args)
{
	int	idx;

	idx = 0;
	while (idx < args->argc - 3)
	{
		get_each_params(argv[idx + 2], idx, args);
		idx++;
	}
}
