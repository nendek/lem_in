/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:33:13 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:33:14 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isnot_in(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int			ft_comp_type2(char c)
{
	if (c != '#' && c != '0' && c != '-' && c != '+' && c != ' ')
		if (c != 'h' && c != 'l' && c != 'j' && c != 'z' && c != '.')
			if (ft_isdigit(c) == 0)
				if (ft_isnot_in(g_tab_char, c))
					return (1);
	return (0);
}

int			ft_comp_type(char c, char *tab)
{
	int	i;

	i = 0;
	if (c && tab)
	{
		while (tab[i] && c != tab[i])
			i++;
		if (tab[i] == c)
			return (1);
		else
			return (0);
	}
	return (0);
}

int			ft_count(char *s)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	if (s[0] != '%' && s[0] != '\0')
		nb++;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			nb++;
			while (!(ft_comp_type(s[i], g_tab_char)) && \
					ft_comp_type2(s[i]) == 0 && s[i] != '\0')
				i++;
			if (ft_comp_type2(s[i]) == 1 && s[i] != '\0')
				nb++;
			else if (s[i + 1] != '%' && s[i + 1] != '\0' && s[i] != '\0')
				nb++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (nb);
}
