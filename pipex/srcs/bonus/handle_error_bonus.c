/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:09:26 by jun               #+#    #+#             */
/*   Updated: 2021/07/21 15:10:15 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/ft_pipex_bonus.h"

void	is_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}