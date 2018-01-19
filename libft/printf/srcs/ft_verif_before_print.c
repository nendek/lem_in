/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_before_print.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:34:22 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:34:25 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_other(int **tab, int i, int *j, int *nb)
{
	while (tab[i][*j] != '\0')
	{
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
			(*nb)++;
		}
		else if (MB_CUR_MAX == 4 && tab[i][*j] != -1)
			*nb += 1;
		else if (tab[i][*j] < 256 && MB_CUR_MAX == 1)
			(*nb)++;
		else if (tab[i][*j] >= 256 && MB_CUR_MAX == 1)
			return (-1);
		else if (tab[i][*j] == -1)
			return (-1);
		(*j)++;
	}
	return (1);
}

int			ft_verif_before_print(int **tab, int k, char *str, int *l)
{
	int		nb;
	int		i;
	int		j;

	nb = 0;
	i = 0;
	j = 0;
	while (i < k)
	{
		if (tab[i] == NULL && (str[i] == 's' || str[i] == 'S'))
			nb += 6;
		else if (str[i] == 'c' || str[i] == 'C' || str[i] == 'S'\
				|| str[i] == 's')
		{
			if (ft_print_char(tab, i, &j, &nb) == -1)
				return (-1);
		}
		else if (tab[i] != NULL)
			ft_print_other(tab, i, &j, &nb);
		i++;
		j = 0;
		(*l)++;
	}
	return (nb);
}
