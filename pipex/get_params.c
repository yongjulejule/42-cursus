/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:14:23 by jun               #+#    #+#             */
/*   Updated: 2021/07/12 21:20:23 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static	int	is_charset(char c, char *charset)
{
	if (!charset)
		return (0);
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

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
	int len;

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

static	void	get_each_params(char *cmdset, int cmd_idx, t_args *args)
{
	int	start;
	int	len;
	int param_idx;
	int size;

	param_idx = 0;
	len = 0;
	start = len;
	size = count_params(cmdset);
	args->cmd_w_params[cmd_idx] =
		(char **)ft_calloc_w_error(sizeof(char *), size + 1);
	while (param_idx < size)
	{
		while (is_charset(cmdset[start], "\t\n\v\f\r "))
			start++;
		len = start;
		if (is_charset(cmdset[start], "'"))
		{
			len = split_once(&cmdset[start], "'");
			args->cmd_w_params[cmd_idx][param_idx] = ft_substr_w_error(cmdset, start + 1, len - 1);
			param_idx++;
			start = len + start + 1;
			continue ;
		}
		else
			while (!(is_charset(cmdset[len], "\t\n\v\f\r '")) && cmdset[len] != '\0')
				len++;
		args->cmd_w_params[cmd_idx][param_idx] = ft_substr_w_error(cmdset, start, len);
		param_idx++;
		start = len;
	}
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
