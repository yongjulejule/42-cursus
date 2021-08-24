/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 19:50:07 by jun               #+#    #+#             */
/*   Updated: 2021/08/24 16:34:25 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/ft_pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_args	*args;

	args = (t_args *)ft_calloc_w_error(1, sizeof(t_args));
	args->envp = envp;
	check_arg_validity(argc, argv, envp);
	build_structure(argc, argv, envp, args);
	breed_process_recursively(args);
}
