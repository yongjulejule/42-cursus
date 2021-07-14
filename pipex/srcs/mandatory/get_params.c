/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:14:23 by jun               #+#    #+#             */
/*   Updated: 2021/07/13 15:17:06 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/ft_pipex.h"

static	int	split_once(char *str, char *charset)
{
	int	idx;

	idx = 0;
	if (!str)
		return (0);
	if (!*str)
		return (0);
	while (is_charset(*(str + idx), charset))
		idx++;
	while (!is_charset(*(str + idx), charset) && str[idx] != '\0')
		idx++;
	return (idx);
}

static	int	count_params(char *cmdset)
{
	int	size;
	int	start;
	int	len;

	start = 0;
	len = 0;
	size = 0;
	while (cmdset[start] != '\0')
	{
		size++;
		while (is_charset(cmdset[start], "\t\n\v\f\r "))
			start++;
		len = start;
		if (is_charset(cmdset[start], "'"))
			len = split_once(&cmdset[start], "'") + start + 1;
		else
			while (!(is_charset(cmdset[len], "\t\n\v\f\r '")) && cmdset[len] != '\0')
				len++;
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
	len = 0;
	while (p_idx < size)
	{
		while (is_charset(cmdset[start], "\t\n\v\f\r "))
			start++;
		if (is_charset(cmdset[start], "'"))
		{
			len = split_once(&cmdset[start], "'");
			args->params[c_idx][p_idx]
				= ft_substr_w_error(cmdset, start + 1, len - 1);
		}
		else
		{
			len = split_once(&cmdset[start], "\t\n\v\f\r ");
			args->params[c_idx][p_idx] = ft_substr_w_error(cmdset, start, len);
		}
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
