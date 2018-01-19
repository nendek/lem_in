/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:34:43 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:40:14 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_error(int **tab, char *str, int l)
{
	t_norme	i;

	i.nb = 0;
	i.i = 0;
	i.j = 0;
	if (MB_CUR_MAX == 1)
		l--;
	while (i.i < l)
	{
		if (str[i.i] != '\0' && MB_CUR_MAX == 4)
		{
			if (ft_print_error2(&i, str, tab) == -1)
				return (-1);
		}
		else if (MB_CUR_MAX == 1)
		{
			if (ft_printf_error3(&i, str, tab) == -1)
				return (-1);
		}
		i.i++;
		i.j = 0;
	}
	return (i.nb);
}

static void	ft_place(int **tab, int *i, char *str, va_list *ap)
{
	int		j;
	int		*tmp;

	if (!(tmp = ft_strdupw(tab[*i])))
		return ;
	j = 0;
	while (tab[*i][j] != '\0')
		j++;
	str[*i] = tab[*i][--j];
	free(tab[*i]);
	tab[*i] = ft_select_conv(ap, tmp, tab[*i + 1]);
	free(tmp);
}

static int	ft_printf_three(int **tab, char *str, t_norme i, int l)
{
	if (ft_verif_before_print(tab, i.i, str, &l) == -1)
	{
		ft_print_error(tab, str, l);
		while (i.m < i.i)
			free(tab[i.m++]);
		free(tab);
		free(str);
		return (-1);
	}
	i.nb = ft_count_and_print(tab, i.i, str);
	while (i.m < i.i)
		free(tab[i.m++]);
	free(tab);
	free(str);
	return (i.nb);
}

static void	ft_printf_two(t_norme *i, int *l)
{
	*l = 0;
	(*i).i = 0;
	(*i).j = 0;
	(*i).m = 0;
	(*i).nb = 0;
}

int			ft_printf(const char *restrict format, ...)
{
	t_norme i;
	va_list	ap;
	int		**tab;
	char	*str;
	int		l;

	ft_printf_two(&i, &l);
	va_start(ap, format);
	if (!(tab = ft_strsplit_printf((char*)format)))
		return (0);
	while (tab[i.j] != '\0')
		i.j++;
	if (!(str = ft_strnew(i.j)))
		return (0);
	while (i.i < i.j)
	{
		if (tab[i.i][0] == '%')
			ft_place(tab, &(i.i), str, &ap);
		i.i++;
	}
	va_end(ap);
	return (ft_printf_three(tab, str, i, l));
}
