/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:39:26 by jun               #+#    #+#             */
/*   Updated: 2021/07/25 16:13:51 by jun              ###   ########.fr       */
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

/*
**Define operations
*/

# define PA 1
# define PB 2
# define SA 3
# define SB 4
# define SS 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

/*
**Type define
*/

typedef struct s_bst
{
	int		key;
	struct s_bst *parent;
	struct s_bst *left;
	struct s_bst *right;
}	t_bst;

typedef struct s_deq
{
	int				num;
	int				idx;
	struct s_deq	*next;
	struct s_deq	*prev;
}	t_deq;

typedef struct s_stk
{
	int		ac;
	t_deq	*head;
	t_deq	*tail;
}	t_stk;

/*
**Utilities
*/

void	*ft_calloc_w_error(size_t count, size_t size);
char	*ft_substr_w_error(char const *s, unsigned int start, size_t len);
int		split_once(char *str, char *charset);
void	dllst_add_back(t_stk **stk, int num);
void	dllst_add_front(t_stk **stk, int num);

/*
**Parsing and Check Validity
*/

int		*parse_args(int argc, char **argv, int *ac);
int		*strset_to_integer(char **tmp, int *ac);
void	check_validity(int *av_int, int ac);
void	make_stack(t_stk **a, t_stk **b, int *av_int, int ac);
void	indexing_args_by_bst(t_stk *a);
void	do_op(t_stk **a, t_stk **b, t_stk **op, int op_idx);
#endif
