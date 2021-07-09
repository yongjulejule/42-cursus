/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 03:37:17 by yongjule          #+#    #+#             */
/*   Updated: 2021/07/08 10:17:15 by yongjule         ###   ########.fr       */
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
