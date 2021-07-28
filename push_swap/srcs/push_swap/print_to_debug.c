
#include <stdio.h>
#include "../../includes/push_swap.h"

void	print_stack(t_stk *a, t_stk *b, t_stk *op)
{
	int idx;
	t_deq *tmp;

	if (a != NULL)
	{
	printf("a->ac is %d", a->ac);
		idx = 0;
		tmp = a->head->next;
		printf("===================== A iter =================\n");
		while (tmp != a->tail)
		{
			printf("A stack : %d th node, data is %d, idx is %d\n", idx, tmp->num, tmp->idx);
			tmp = tmp->next;
			idx++;
		}
//		idx--;
//		tmp = a->tail->prev;
//		printf("===================== A recur =================\n");
//		while (tmp != a->head)
//		{
//			printf("A stack : %d th node, data is %d, idx is %d\n", idx, tmp->num, tmp->idx);
//			tmp = tmp->prev;
//			idx--;
//		}
	}

	if (b != NULL)
	{
	printf("b->ac is %d", b->ac);
		idx = 0;
		tmp = b->head->next;
		printf("===================== B iter =================\n");
		while (tmp != b->tail)
		{
			printf("B stack : %d th node, data is %d, idx is %d\n", idx, tmp->num, tmp->idx);
			tmp = tmp->next;
			idx++;
		}
//		idx--;
//		tmp = b->tail->prev;
//		printf("===================== B recur =================\n");
//		while (tmp != b->head)
//		{
//			printf("B stack : %d th node, data is %d, idx is %d\n", idx, tmp->num, tmp->idx);
//			tmp = tmp->prev;
//			idx--;
//		}
	}

	if (op != NULL)
	{
	printf("op->ac is %d", op->ac);
		idx = 0;
		tmp = op->head->next;
		printf("===================== OP iter =================\n");
		while (tmp != op->tail)
		{
			printf("op stack : %d th node, data is %d, idx is %d\n", idx, tmp->num, tmp->idx);
			tmp = tmp->next;
			idx++;
		}
		idx--;
		tmp = op->tail->prev;
//		printf("===================== op recur =================\n");
//		while (tmp != op->head)
//		{
//			printf("OP stack : %d th node, data is %d, idx is %d\n", idx, tmp->num, tmp->idx);
//			tmp = tmp->prev;
//			idx--;
//		}
	}
}
