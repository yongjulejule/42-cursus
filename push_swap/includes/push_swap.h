/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:39:26 by jun               #+#    #+#             */
/*   Updated: 2021/07/24 14:27:38 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

#define WSPACE "\t\r\n\v\f "

void	*ft_calloc_w_error(size_t count, size_t size);
char	*ft_substr_w_error(char const *s, unsigned int start, size_t len);
int		split_once(char *str, char *charset);
int		*parse_args(int argc, char **argv, int *ac);
int		*strset_to_integer(char **tmp, int *ac);
void	check_validity(int *av_int, int ac);
#endif
