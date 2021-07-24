/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:39:26 by jun               #+#    #+#             */
/*   Updated: 2021/07/24 17:07:57 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

/*
**My Mecro
*/

# define WSPACE "\t\r\n\v\f "
# define STACK_A 0
# define STACK_B 1

/*
**Type define
*/

typedef struct s_deq
{
	int				num;
	struct s_deq	*next;
	struct s_deq	*prev;
}	t_deq;

typedef struct s_ops
{
	char			*op;
	struct s_ops	*next;
	struct s_ops	*prev;
}	t_ops;

typedef struct s_stk
{
	t_deq	*a;
	t_deq	*b;
	t_deq	*head_a;
	t_deq	*head_b;
	t_deq	*tail_a;
	t_deq	*tail_b;
}	t_stk;

/*
**Utilities
*/

void	*ft_calloc_w_error(size_t count, size_t size);
char	*ft_substr_w_error(char const *s, unsigned int start, size_t len);
int		split_once(char *str, char *charset);
void	cdlst_add_back(t_deq **stack, int num);

/*
**Parsing and Check Validity
*/

int		*parse_args(int argc, char **argv, int *ac);
int		*strset_to_integer(char **tmp, int *ac);
void	check_validity(int *av_int, int ac);
void	make_stack(t_deq **stack_a, t_deq **stack_b, int *av_int, int ac);
#endif
