/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uchar_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 00:20:58 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/20 10:40:56 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_dgt_uchar_len(unsigned char nbr, t_ui base)
{
	int cnt;

	cnt = 0;
	if (base < 2)
		return (0);
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= base;
		cnt++;
	}
	return (cnt);
}

static	void	make_nbr(unsigned char n, int fd)
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

void			ft_putnbr_uchar_fd(unsigned char n, int fd)
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
