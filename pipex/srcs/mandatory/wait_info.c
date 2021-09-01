/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:01:01 by jun               #+#    #+#             */
/*   Updated: 2021/09/01 17:15:24 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/ft_pipex.h"

int wstatus(int status)
{
	return (status & 0177);
}

int	wifexited(int status)
{
	return (wstatus(status) == 0);
}

int wifsignaled(int status)
{
	return (wstatus(status) != 0177 && wstatus(status) != 0);
}

int wexitstatus(int status)
{
	return ((status >> 8) & 0x000000ff);
}

int	wtermsig(int status)
{
	return (wstatus(status));
}
