/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:06:22 by jun               #+#    #+#             */
/*   Updated: 2021/09/01 12:18:53 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/ft_pipex.h"

void	is_error(char *str_1, char *str_2, int exit_status)
{
	if (*str_2 == '\0')
		ft_putstr_fd("zsh: permission denied:", 2);
	else
	{
		ft_putstr_fd(str_1, 2);
		ft_putendl_fd(str_2, 2);
	}
	exit(exit_status);
}
