
#include <stdio.h>
#include "../../includes/push_swap.h"

static	void	make_nbr(int n)
{
	char	c;
	static int a;

	if (a == 7)
	{
		a = 0;
		return ;
	}
	a++;
	c = "01"[n % 2];
	n /= 2;
	make_nbr(n);
	write(1, &c, 1);
}

static void	ft_putnbr_ui_base(int n)
{
	if (n == 0)
	{
		write(1, "0000000", 7);
		return ;
	}
	make_nbr(n);
}

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
			ft_putnbr_ui_base(tmp->idx);
			printf("A stack : %d th node, data is %d, idx is %d\n", idx, tmp->num, tmp->idx);
			tmp = tmp->next;
			idx++;
		}
	}

	if (b != NULL)
	{
		printf("b->ac is %d", b->ac);
		idx = 0;
		tmp = b->head->next;
		printf("===================== B iter =================\n");
		while (tmp != b->tail)
		{
			ft_putnbr_ui_base(tmp->idx);
			printf("B stack : %d th node, data is %d, idx is %d\n", idx, tmp->num, tmp->idx);
			tmp = tmp->next;
			idx++;
		}
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
	}
}
