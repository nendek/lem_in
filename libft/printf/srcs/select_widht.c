/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_widht.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:35:36 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:35:37 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_width_bis(char *str, int *j, int *k)
{
	(*k)++;
	(*j)--;
	while (ft_isdigit(str[*j]) == 1)
	{
		(*k)++;
		(*j)--;
	}
}

static char	*ft_width_ter(char *str, int *i, int *j, int *k)
{
	int		l;
	char	*ret;

	l = 0;
	(*j)++;
	if (!(ret = ft_strnew(*k)))
		return (NULL);
	*i = *j + *k;
	while (*j != *i)
	{
		ret[l] = str[*j];
		l++;
		(*j)++;
	}
	return (ret);
}

static void	ft_width_2(int *k, int *j)
{
	*k = 0;
	*j = 1;
}

int			ft_width(char *str, int *i, t_param *param)
{
	char	*ret;
	int		j;
	int		k;

	ft_width_2(&k, &j);
	while (str[j] != '\0')
		j++;
	while (j >= 1)
	{
		while (ft_isdigit(str[j]) == 0 && j >= 1)
			j--;
		if (ft_isdigit(str[j]) == 1)
		{
			ft_width_bis(str, &j, &k);
			if (str[j] != '.')
			{
				if (!(ret = ft_width_ter(str, i, &j, &k)))
					return (0);
				param->width = ft_atoi(ret);
				free(ret);
				return (1);
			}
		}
	}
	return (1);
}
