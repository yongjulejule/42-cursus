/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:45:17 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/24 11:10:28 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <limits.h>
# include "libft/libft.h"

/*
** MY MECRO
*/

# define IS_NOT_FLAG -1
# define IS_FLAGS 0
# define ERROR_FLAG 0
# define SUCCESS_FLAG 1
# define SPECS "diunpxXcs%"
# define HEX_S "0123456789abcdef"
# define HEX_L "0123456789ABCDEF"

/*
** HANDLE UTF-8
*/

# define UTF_8_1 0x7F
# define UTF_8_2 0x7FF
# define UTF_8_3 0xFFFF
# define UTF_8_4 0x1FFFFF
# define UTF_MASK_0 0x80
# define UTF_MASK_1 0x70
# define UTF_MASK_2 0xC0
# define UTF_MASK_3 0xE0
# define UTF_MASK_4 0xF0

/*
** DEFINE TYPES
*/

typedef long long			t_ll;
typedef unsigned int		t_ui;
typedef unsigned long		t_ul;
typedef unsigned long long	t_ull;

/*
** HANDLE OPTIONS
*/

typedef struct	s_opts
{
	int	flags;
	int	width;
	int precision;
	int length;
	int spec;
}				t_opts;

/*
** LINKED LIST WITH OPTIONS
*/

typedef struct	s_lidx
{
	int				info;
	char			*txt;
	struct s_lidx	*next;
	struct s_opts	opts;
}				t_lidx;

int				ft_printf(const char *formet, ...);

/*
** PARSING
*/

int				parsing(char *formet, t_lidx **strs);
void			check_flags(t_lidx *str);
int				ft_split_for_pf(char *format, t_lidx **strs);

/*
** HANDLE LISTS
*/

void			ft_lidxadd_back(t_lidx **lst, t_lidx *newnode);
void			ft_lidxclear(t_lidx **lst, void (*del)(void*));
void			ft_lidxdelone(t_lidx *lst, void (*del)(void*));
t_lidx			*ft_lidxnew(void *txt, int info);
t_lidx			*ft_lidxlast(t_lidx *lst);

/*
** PRINTING
*/

int				go_print(va_list ap, t_lidx *strs);
int				get_width_len(va_list ap, t_lidx *strs);
int				get_precision_len(va_list ap, t_lidx *strs);
void			ft_print_sign(va_list ap, t_lidx *strs);
void			ft_print_str(va_list ap, t_lidx *strs);
void			ft_print_width(t_lidx *strs, char c, int len);
void			ft_print_char(va_list ap, t_lidx *strs);
void			ft_print_deci(va_list ap, t_lidx *strs);
void			ft_print_deci_nbr(va_list ap, t_lidx *strs);
void			ft_print_hexa(va_list ap, t_lidx *strs);
void			ft_print_hash(t_lidx *strs, va_list ap);
void			ft_print_hexa_nbr(va_list ap, t_lidx *strs);

/*
** PRINT AS TYPE
*/

void			ft_putnbr_abs_fd(int n, int fd);
void			ft_putnbr_char_fd(char n, int fd);
void			ft_putnbr_uchar_fd(unsigned char n, int fd);
void			ft_putnbr_l_fd(long n, int fd);
void			ft_putnbr_ll_fd(t_ll n, int fd);
void			ft_putnbr_short_fd(short n, int fd);
void			ft_putnbr_ushort_fd(unsigned short n, int fd);
void			ft_putnbr_ul_fd(t_ul n, int fd);
void			ft_putnbr_ull_fd(t_ull n, int fd);
void			ft_putnbr_ui_fd(t_ui n, int fd);
void			ft_putchar_utf_fd(t_lidx *strs, t_ui uni, int fd);
void			ft_putnbr_ui_hexa_fd(t_lidx *strs, t_ui n, int fd);
void			ft_putnbr_ul_hexa_fd(t_lidx *strs, t_ul n, int fd);
void			ft_putnbr_ull_hexa_fd(t_lidx *strs, t_ull n, int fd);
void			ft_putnbr_uchar_hexa_fd(t_lidx *strs, unsigned char n, int fd);
void			ft_putnbr_ushort_hexa_fd(t_lidx *strs,\
				unsigned short n, int fd);

/*
** GET SIZE
*/

int				ft_dgtlen(int nbr, t_ui base);
int				ft_dgt_char_len(char nbr, t_ui base);
int				ft_dgt_uchar_len(unsigned char nbr, t_ui base);
int				ft_dgt_l_len(long nbr, t_ui base);
int				ft_dgt_ll_len(t_ll nbr, t_ui base);
int				ft_dgt_short_len(short nbr, t_ui base);
int				ft_dgt_ushort_len(unsigned short nbr, t_ui base);
int				ft_dgt_ul_len(t_ul nbr, t_ui base);
int				ft_dgt_ull_len(t_ull nbr, t_ui base);
int				ft_dgt_ui_len(t_ui nbr, t_ui base);
int				get_nbr_len(va_list ap, t_lidx *strs, int base);
int				get_sign(va_list ap, t_lidx *strs);
int				get_length_flag(t_lidx *strs);
size_t			ft_utf_last_len(wchar_t *utf_str, int len);
size_t			ft_utf_byte_len(wchar_t *utf_str);
size_t			ft_utf_put_byte(wchar_t utf_str, int len);
size_t			ft_utf_byte_chr_len(va_list ap);
void			get_uchar_byte(va_list ap, t_ull total_len);
void			get_ushort_byte(va_list ap, t_ull total_len);
void			get_ul_byte(va_list ap, t_ull total_len);
void			get_ull_byte(va_list ap, t_ull total_len);
void			get_ui_byte(va_list ap, t_ull total_len);

/*
** UTILS
*/

int				is_zero_nbr(va_list cp_nbr, t_lidx *strs);
void			ft_handle_n_spec(va_list ap, t_lidx *strs, t_ull total_len);
#endif
