/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:25:28 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/28 18:45:33 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_lidx	*strs;
	int		len;

	if (!format)
		return (-1);
	if (*format == '\0')
		return (0);
	if (!parsing((char*)format, &strs))
		return (-1);
	va_start(ap, format);
	len = go_print(ap, strs);
	va_end(ap);
	return (len);
}
