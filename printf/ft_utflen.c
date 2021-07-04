/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utflen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:30:49 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/24 10:07:31 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_utf_last_len(wchar_t *utf_str, int len)
{
	int	idx;

	idx = 0;
	while (idx < len)
	{
		len = ft_utf_put_byte(utf_str[idx], len);
		len--;
		idx++;
	}
	return (len);
}

size_t	ft_utf_put_byte(wchar_t utf_str, int len)
{
	if (utf_str <= UTF_8_1)
		return (len -= 0);
	else if (utf_str <= UTF_8_2)
		return (len -= 1);
	else if (utf_str <= UTF_8_3)
		return (len -= 2);
	else if (utf_str <= UTF_8_4)
		return (len -= 3);
	else
		return (len -= 0);
}

size_t	ft_utf_byte_len(wchar_t *utf_str)
{
	size_t	len;
	size_t	byte;

	len = 0;
	byte = 0;
	while (utf_str[len])
	{
		if (utf_str[len] <= UTF_8_1)
			byte += 1;
		else if (utf_str[len] <= UTF_8_2)
			byte += 2;
		else if (utf_str[len] <= UTF_8_3)
			byte += 3;
		else if (utf_str[len] <= UTF_8_4)
			byte += 4;
		else
			byte += 1;
		len++;
	}
	return (byte);
}

size_t	ft_utf_byte_chr_len(va_list ap)
{
	va_list	cp_ap;
	wchar_t	wc;
	size_t	byte;

	va_copy(cp_ap, ap);
	wc = va_arg(cp_ap, wchar_t);
	va_end(cp_ap);
	byte = 0;
	if (wc <= UTF_8_1)
		byte += 1;
	else if (wc <= UTF_8_2)
		byte += 2;
	else if (wc <= UTF_8_3)
		byte += 3;
	else if (wc <= UTF_8_4)
		byte += 4;
	else
		byte += 1;
	byte--;
	return (byte);
}
