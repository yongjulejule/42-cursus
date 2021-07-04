/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_abs_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:31:31 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/20 11:34:08 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_dgtlen(int nbr, t_ui base)
{
	int cnt;

	cnt = 0;
	if (base < 2)
		return (0);
	if (nbr == INT_MIN)
		nbr++;
	if (nbr < 0)
		nbr *= -1;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= base;
		cnt++;
	}
	return (cnt);
}

static void	make_nbr(int n, int fd)
{
	int		digit;
	char	c;

	if (n == 0)
		return ;
	digit = n % 10;
	if (digit < 0)
		digit *= -1;
	c = digit + '0';
	n /= 10;
	make_nbr(n, fd);
	write(fd, &c, 1);
}

void		ft_putnbr_abs_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	make_nbr(n, fd);
}
