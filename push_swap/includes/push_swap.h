/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:39:26 by jun               #+#    #+#             */
/*   Updated: 2021/07/31 16:35:23 by jun              ###   ########.fr       */
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
	int		pivot;
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
void	dllst_delone(t_stk **stk, t_deq *del);
void	dllst_del_n_node(t_stk **stk, t_deq *del, int nbr);
void	dllst_append(t_stk **src, t_stk **dst);

void	compress_rotation(t_stk **op);
void	compress_r_revr(t_stk **op);
void	compress_push(t_stk **op);
/*
**Parsing and Check Validity
*/

int		*parse_args(int argc, char **argv, int *ac);
int		*strset_to_integer(char **tmp, int *ac);
void	check_validity(int *av_int, int ac);
void	make_stack(t_stk **a, t_stk **b, int *av_int, int ac);
void	indexing_args_by_bst(t_stk *a);

/*
**Operations
*/

void	do_op(t_stk **a, t_stk **b, t_stk **op, int op_idx);



int		pow_to_get_pivot(int nbr);

void	divide_data(t_stk **a, t_stk **b, t_stk **op);
void	merge_stack(t_stk **a, t_stk **b, t_stk **op);
void	sort_each_stack(t_stk **a, t_stk **b, t_stk **op);
void	compress_each_op(t_stk **op_a, t_stk **op_b);

void	print_result(t_stk **op);
void	joint_stack(t_stk **op, t_stk **op_a, t_stk **op_b);


int		get_most_sigf_bit(int num);
void	radix_msd_sort(t_stk **a, t_stk **b, t_stk **op, int cnt);
void	transf_based_bits(t_stk **a, t_stk **b, t_stk **op);


void	subprocess_a_to_b(t_stk **a, t_stk **b, t_stk **op, int shift);
int		transf_a_to_b_0(t_stk **a, t_stk **b, t_stk **op, int shift);
int		transf_a_to_b_1(t_stk **a, t_stk **b, t_stk **op, int shift);
void	subprocess_b_to_a(t_stk **a, t_stk **b, t_stk **op, int shift);
int		transf_b_to_a_0(t_stk **a, t_stk **b, t_stk **op, int shift);
int		transf_b_to_a_1(t_stk **a, t_stk **b, t_stk **op, int shift);

void init_transf(t_stk **a, t_stk **b, t_stk **op);

// !!!!!!!!!!!!!!!!!debuging!!!!!!!!!!!!!!!!!!!!!!!!! (delete before submit)
void	print_stack(t_stk *a, t_stk *b, t_stk *op, char *str);
#endif
