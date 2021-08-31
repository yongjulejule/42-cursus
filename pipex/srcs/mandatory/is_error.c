/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:06:22 by jun               #+#    #+#             */
/*   Updated: 2021/08/31 13:59:32 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/ft_pipex.h"

// execve 오류면 exit(127)
void	is_error(char *str_1, char *str_2)
{
	extern int	errno;

	if (*str_2 == '\0')
		ft_putstr_fd("zsh: permission denied:", 2);
	else
	{
		ft_putstr_fd(str_1, 2);
		ft_putendl_fd(str_2, 2);
	}
	exit(errno);
}
