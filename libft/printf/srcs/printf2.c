/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:34:50 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:34:51 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_other(int **tab, int i, int *j, int *nb)
{
	while (tab[i][*j] != '\0')
	{
		ft_putchar(tab[i][*j]);
		(*j)++;
		(*nb)++;
	}
}

static int	ft_print_char(int **tab, int i, int *j, int *nb)
{
	while (tab[i][*j] != 0)
	{
		if (tab[i][*j] == -3)
		{
			ft_putchar(0);
			(*nb)++;
		}
		else if (MB_CUR_MAX == 4 && tab[i][*j] != -1)
			*nb = *nb + ft_wputchar(tab[i][*j]);
		else if (tab[i][*j] < 256 && MB_CUR_MAX == 1)
		{
			write(1, &tab[i][*j], 1);
			(*nb)++;
		}
		else if (tab[i][*j] >= 256 && MB_CUR_MAX == 1)
			return (-1);
		else if (tab[i][*j] == -1)
			return (-1);
		(*j)++;
	}
	return (1);
}

int			ft_count_and_print(int **tab, int k, char *str)
{
	int		nb;
	t_norme i;

	nb = 0;
	i.i = 0;
	i.j = 0;
	while (i.i < k)
	{
		if (tab[i.i] == NULL && (str[i.i] == 's' || str[i.i] == 'S'))
		{
			ft_putstr("(null)");
			nb += 6;
		}
		else if (str[i.i] == 'c' || str[i.i] == 'C' || str[i.i] == 'S'\
				|| str[i.i] == 's')
		{
			if (ft_print_char(tab, i.i, &(i.j), &nb) == -1)
				return (-1);
		}
		else if (tab[i.i] != NULL)
			ft_print_other(tab, i.i, &(i.j), &nb);
		i.i++;
		i.j = 0;
	}
	return (nb);
}

int			ft_print_error2(t_norme *i, char *str, int **tab)
{
	if (tab[(*i).i] == NULL && (str[(*i).i] == 's' || str[(*i).i] == 'S'))
	{
		ft_putstr("(null)");
		(*i).nb += 6;
	}
	else if (str[(*i).i] == 'c' || str[(*i).i] == 'C' || str[(*i).i] == 'S'\
			|| str[(*i).i] == 's')
	{
		if (ft_print_char(tab, (*i).i, &(*i).j, &(*i).nb) == -1)
			return (-1);
	}
	else if (tab[(*i).i] != NULL)
		ft_print_other(tab, (*i).i, &(*i).j, &(*i).nb);
	return (1);
}

int			ft_printf_error3(t_norme *i, char *str, int **tab)
{
	if (tab[(*i).i] == NULL && (str[(*i).i] == 's' || str[(*i).i] == 'S'))
	{
		ft_putstr("(null)");
		(*i).nb += 6;
	}
	else if (str[(*i).i] == 'c' || str[(*i).i] == 'C' || str[(*i).i] == 'S'\
			|| str[(*i).i] == 's')
	{
		if (ft_print_char(tab, (*i).i, &(*i).j, &(*i).nb) == -1)
			return (-1);
	}
	else if (tab[(*i).i] != NULL)
		ft_print_other(tab, (*i).i, &(*i).j, &(*i).nb);
	return (1);
}
