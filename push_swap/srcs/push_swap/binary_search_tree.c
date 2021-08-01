/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 12:48:26 by jun               #+#    #+#             */
/*   Updated: 2021/08/01 13:25:34 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_bst	*init_newnode(int key)
{
	t_bst	*newnode;

	newnode = (t_bst *)ft_calloc_w_error(sizeof(t_bst), 1);
	newnode->parent = NULL;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->key = key;
	return (newnode);
}

static void	insert_node(t_bst **root, int key)
{
	t_bst	*newnode;
	t_bst	*node_x;
	t_bst	*node_y;

	newnode = init_newnode(key);
	node_y = NULL;
	node_x = *root;
	while (node_x)
	{
		node_y = node_x;
		if (key < node_x->key)
			node_x = node_x->left;
		else
			node_x = node_x->right;
	}
	newnode->parent = node_y;
	if (node_y == NULL)
		*root = newnode;
	else if (newnode->key < node_y->key)
		node_y->left = newnode;
	else
		node_y->right = newnode;
}

static void	inorder_to_idxing(t_bst *node, t_stk *a, t_deq *cur)
{
	static int	idx = 1;

	if (node != NULL)
	{
		inorder_to_idxing(node->left, a, cur);
		while (cur != a->tail)
		{
			if (cur->num == node->key)
			{
				cur->idx = idx;
				idx++;
				break ;
			}
			cur = cur->next;
		}
		cur = a->head->next;
		inorder_to_idxing(node->right, a, cur);
	}
}

static void	postorder_to_free(t_bst *node)
{
	if (node != NULL)
	{
		postorder_to_free(node->left);
		postorder_to_free(node->right);
		free(node);
	}
}

void	indexing_args_by_bst(t_stk *a)
{
	t_bst	**bst;
	t_deq	*cur;

	cur = a->head->next;
	bst = (t_bst **)ft_calloc_w_error(sizeof(t_bst *), 1);
	while (cur != a->tail)
	{
		insert_node(bst, cur->num);
		cur = cur->next;
	}
	cur = a->head->next;
	inorder_to_idxing(*bst, a, cur);
	postorder_to_free(*bst);
	bst = NULL;
}
