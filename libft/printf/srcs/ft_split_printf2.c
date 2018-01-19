/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_printf2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:33:20 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:33:22 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_countsize_one(int *tab, t_norme *y)
{
	tab[(*y).j++] = (*y).size;
	return (1);
}

static void	ft_countsize_two(char *s, t_norme *y)
{
	while (!(ft_comp_type(s[(*y).i], g_tab_char)) \
			&& ft_comp_type2(s[(*y).i]) == 0 && s[(*y).i])
	{
		(*y).size++;
		(*y).i++;
	}
}

static void	ft_countsize_three(char *s, t_norme *y, int *tab, int *k)
{
	(*y).size = 1;
	(*y).i++;
	if (ft_comp_type2(s[(*y).i]) == 0)
	{
		ft_countsize_two(s, y);
		if (ft_comp_type2(s[(*y).i]) == 0)
			tab[(*y).j++] = ++((*y).size);
		else
			*k = ft_countsize_one(tab, y);
	}
	else
		*k = ft_countsize_one(tab, y);
	(*y).size = 0;
}

void		ft_countsize(char *s, int *tab)
{
	t_norme	y;
	int		k;

	y.i = 0;
	y.j = 0;
	y.size = 0;
	if (tab && s)
		while (s[y.i])
		{
			k = 0;
			if (s[y.i] != '%')
				y.size++;
			if ((s[y.i + 1] == '\0' && s[y.i] != '%') || \
					(s[y.i] == '%' && y.size != 0))
				tab[y.j++] = y.size;
			if (s[y.i] == '%')
				ft_countsize_three(s, &y, tab, &k);
			if (k == 0)
				y.i++;
		}
}
