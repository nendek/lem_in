/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:31:23 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/17 15:29:26 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <limits.h>
# include <wchar.h>

typedef struct		s_param
{
	char	flags[5];
	char	type_width;
	size_t	width;
	int		precision;
	char	modifier[2];
	char	conv;
}					t_param;

typedef struct		s_norme
{
	int		i;
	int		j;
	int		size;
	int		nb;
	int		m;
}					t_norme;

int					ft_printf(const char *restrict format, ...);
void				ft_remp_left_preci_two(char *str, t_param param);
int					ft_count_and_print(int **tab, int k, char *str);
int					ft_print_error2(t_norme *i, char *str, int **tab);
int					ft_printf_error3(t_norme *i, char *str, int **tab);
int					ft_read_param(char *str, int *i,\
		t_param *param, int *verif);
void				ft_call_two(int *str, int *tmp);
int					ft_verif_before_print(int **tab, int k, char *str, int *l);
void				ft_remp_hex_left(char *str, int i,\
		t_param param, unsigned long long int var);
void				ft_remp_base_left(char *str, int i,\
		t_param param, unsigned long long int var);
void				ft_remp_left_hex(char *str, t_param param);
char				*ft_base_hexa(unsigned long long int nb, t_param param);
int					ft_comp_type(char c, char *tab);
int					ft_comp_type2(char c);
int					ft_count(char *s);
void				ft_countsize(char *s, int *tab);
void				ft_remp_smaj_right_bis(int *str, int *tmp,\
		int i, t_param param);
void				ft_remp_s_right_bis(char *str, char\
		*tmp, int i, t_param param);
void				ft_modifier_pnt(int *i, int *j, t_param *param);
void				ft_modifier_car(int *i, int *j, t_param *param);
void				ft_modifier_ter(char *str, int *i, int *j, t_param *param);
void				ft_modifier_bis(char *str, int *i, int *j, t_param *param);
int					ft_unicode(int c);
void				ft_remp_s_right(char *str, char *tmp, int i, t_param param);
void				ft_remp_s_left(char *str, char *tmp, int i, t_param param);
void				ft_remp_smaj_right(int *str, int *tmp,\
		int i, t_param param);
void				ft_remp_smaj_left(int *str, int *tmp, int i, t_param param);
void				ft_remp_hex_right(char *str, int i,\
		t_param param, unsigned long long int var);
void				ft_remp_unsigned_right_bis(char *str,\
		t_param param, unsigned long long int var);
void				ft_remp_base_right(char *str, int i,\
		t_param param, unsigned long long int var);
int					**ft_strsplit_printf(char *str);
void				ft_remp_unsigned_left(char *str, \
		unsigned long long int var, int i, t_param param);
void				ft_remp_unsigned_right_birm(int j, char *str);
void				ft_remp_unsigned_right(char *str, \
		unsigned long long int var, int i, t_param param);
void				ft_remp_left_preci(char *str);
void				ft_remp_left(char *str, \
		long long var, int i, t_param param);
void				ft_remp_right(char *str, \
		long long var, int i, t_param param);
int					ft_width(char *str, int *i, t_param *param);
int					ft_precision(char *str, int *i, t_param *param);
int					*ft_select_conv(va_list *ap, int *str, int *verif);
int					*ft_flags_c(int c, t_param param);
int					*ft_flags_smaj(int *str, t_param param);
int					*ft_convert_n(va_list *ap, t_param param);
int					*ft_convert_s(va_list *ap, t_param param);
int					*ft_convert_smaj(va_list *ap, t_param param);
int					*ft_convert_p(va_list *ap, t_param param);
int					*ft_convert_d(va_list *ap, t_param param);
int					*ft_convert_dmaj(va_list *ap, t_param param);
int					*ft_convert_i(va_list *ap, t_param param);
int					*ft_convert_o(va_list *ap, t_param param);
int					*ft_convert_omaj(va_list *ap, t_param param);
int					*ft_convert_u(va_list *ap, t_param param);
int					*ft_convert_umaj(va_list *ap, t_param param);
int					*ft_convert_x(va_list *ap, t_param param);
int					*ft_convert_xmaj(va_list *ap, t_param param);
int					*ft_convert_c(va_list *ap, t_param param);
int					*ft_convert_cmaj(va_list *ap, t_param param);
int					*ft_convert_percent(va_list *ap, t_param param);

static char			g_base_oct[9] =
{
	'0',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'\0'
};

static char			g_null[] =
{
	'(',
	'n',
	'u',
	'l',
	'l',
	')',
	'\0'
};

static char			g_tab_char[] =
{
	's',
	'S',
	'p',
	'd',
	'D',
	'i',
	'o',
	'O',
	'u',
	'U',
	'x',
	'X',
	'c',
	'C',
	'%',
	'\0'
};

static char			g_tab_flags[5] =
{
	'#',
	'0',
	'-',
	'+',
	' '
};

static char			g_tab_modifier[4] =
{
	'h',
	'l',
	'j',
	'z',
};

static int			*(*g_tab_ptrf[])(va_list *ap, t_param param) =
{
	ft_convert_s,
	ft_convert_smaj,
	ft_convert_p,
	ft_convert_d,
	ft_convert_dmaj,
	ft_convert_i,
	ft_convert_o,
	ft_convert_omaj,
	ft_convert_u,
	ft_convert_umaj,
	ft_convert_x,
	ft_convert_xmaj,
	ft_convert_c,
	ft_convert_cmaj,
	ft_convert_percent,
};

static char			g_base_hex[17] =
{
	'0',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
	'a',
	'b',
	'c',
	'd',
	'e',
	'f',
	'\0'
};

static char			g_ret_two[17] =
{
	'1',
	'1',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'1',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'\0'
};

static char			g_ret_three[25] =
{
	'1',
	'1',
	'1',
	'0',
	'0',
	'0',
	'0',
	'0',
	'1',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'1',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'\0'
};

static char			g_ret_four[33] =
{
	'1',
	'1',
	'1',
	'1',
	'0',
	'0',
	'0',
	'0',
	'1',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'1',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'1',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'\0'
};

#endif
