/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_uft_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:14:41 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/17 11:33:45 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	putchar_utf_4(t_ui uni, int fd)
{
	unsigned char	bits[4];
	int				idx;

	idx = 3;
	while (idx > 0)
	{
		bits[idx] = (unsigned char)(UTF_MASK_0 | (uni & 0x3F));
		uni >>= 6;
		idx--;
	}
	bits[0] = (unsigned char)(UTF_MASK_4 | uni);
	idx = 0;
	while (idx < 4)
	{
		write(fd, &bits[idx], 1);
		idx++;
	}
}

static	void	putchar_utf_3(t_ui uni, int fd)
{
	unsigned char	bits[3];
	int				idx;

	idx = 2;
	while (idx > 0)
	{
		bits[idx] = (unsigned char)(UTF_MASK_0 | (uni & 0x3F));
		uni >>= 6;
		idx--;
	}
	bits[0] = (unsigned char)(UTF_MASK_3 | uni);
	idx = 0;
	while (idx < 3)
	{
		write(fd, &bits[idx], 1);
		idx++;
	}
}

static	void	putchar_utf_2(t_ui uni, int fd)
{
	unsigned char	bits[2];

	bits[1] = (unsigned char)(UTF_MASK_0 | (uni & 0x3F));
	uni >>= 6;
	bits[0] = (unsigned char)(UTF_MASK_2 | uni);
	write(fd, &bits[0], 1);
	write(fd, &bits[1], 1);
}

static	void	putchar_utf_1(t_ui uni, int fd)
{
	write(fd, &uni, 1);
}

void			ft_putchar_utf_fd(t_lidx *strs, t_ui uni, int fd)
{
	if (uni <= UTF_8_1)
	{
		putchar_utf_1(uni, fd);
		strs->info += 1;
	}
	else if (uni <= UTF_8_2)
	{
		putchar_utf_2(uni, fd);
		strs->info += 2;
	}
	else if (uni <= UTF_8_3)
	{
		putchar_utf_3(uni, fd);
		strs->info += 3;
	}
	else if (uni <= UTF_8_4)
	{
		putchar_utf_4(uni, fd);
		strs->info += 4;
	}
	else
	{
		ft_putchar_fd(uni, fd);
		strs->info += 1;
	}
}
