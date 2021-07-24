/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:14:23 by jun               #+#    #+#             */
/*   Updated: 2021/07/24 13:32:53 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
		while (is_charset(cmdset[start], WSPACE))
			start++;
		len = split_once(&cmdset[start], WSPACE);
		start = len + start;
	}
	return (size);
}

static	int	make_string(char *arg, char **tmp, int tmp_idx)
{
	int	start;
	int	len;

	start = 0;
	while (arg[start])
	{
		while (is_charset(arg[start], WSPACE))
			start++;
		len = split_once(&arg[start], WSPACE);
		tmp[tmp_idx] = ft_substr_w_error(arg, start, len);
		tmp_idx++;
		start = len + start;
	}
	return (tmp_idx);
}

static	char	**get_args_as_str(char **args, int size)
{
	int		av_idx;
	int		tmp_idx;
	char	**tmp;

	tmp = (char **)ft_calloc_w_error(sizeof(char *), size + 1);
	av_idx = 1;
	tmp_idx = 0;
	while (args[av_idx])
	{
		tmp_idx = make_string(args[av_idx], tmp, tmp_idx);
		av_idx++;
	}
	return (tmp);
}

static	char	**get_each_args(char **args)
{
	int		size;
	int		idx;

	size = 0;
	idx = 1;
	while (args[idx])
	{
		size += count_params(args[idx]);
		idx++;
	}
	return (get_args_as_str(args, size));
}

int	*parse_args(int argc, char **argv, int *ac)
{
	int		idx;
	char	**tmp;

	idx = 0;
	while (idx < argc)
	{
		argv[idx] = ft_strtrim(argv[idx], WSPACE);
		idx++;
	}
	tmp = get_each_args(argv);
	idx = 0;
	while (idx < argc)
	{
		free(argv[idx]);
		idx++;
	}
	return (strset_to_integer(tmp, ac));
}
