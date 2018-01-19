/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smaj_remp_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:33:01 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:46:34 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_remp_smaj_right_preci_two(int *str, int *i, t_param param)
{
	if (ft_is_in_at(param.flags, '0', 5))
		str[(*i)--] = '0';
	else
		str[(*i)--] = ' ';
}

static void	ft_remp_smaj_right_widht_two(int *str, int *tmp, t_param param,\
		int j)
{
	j = 0;
	while (param.precision > 0)
	{
		str[j] = tmp[j];
		j++;
		param.precision--;
	}
}

static void	ft_remp_smaj_right_preci(int *str, int *tmp, int i, t_param param)
{
	int		j;
	int		k;

	k = ((int)param.width > i) ? (int)param.width - 1 : i - 1;
	if (param.width == 0 && tmp[0] == 0)
		return ;
	j = i - 1;
	if (i <= param.precision)
	{
		while (tmp[j] != '\0' && j >= 0)
		{
			str[k] = tmp[j];
			j--;
			k--;
			param.width--;
		}
		while (k >= 0)
			ft_remp_smaj_right_preci_two(str, &k, param);
	}
	else
		ft_remp_smaj_right_widht_two(str, tmp, param, j);
}

static void	ft_remp_smaj_right_width(int *str, int *tmp, int i, t_param param)
{
	int		j;

	j = 0;
	if (param.width == 0 && tmp[0] == 0)
		return ;
	j = (i >= param.precision) ? param.precision - 1 : i - 1;
	i--;
	while (param.precision > 0)
	{
		if (tmp[j] != '\0')
			str[i] = tmp[j];
		if (ft_is_in_at(param.flags, '0', 5) && tmp[0] == '\0')
			str[i] = '0';
		else if (tmp[0] == '\0')
			str[i] = ' ';
		if (j >= 0)
			i--;
		j--;
		param.precision--;
	}
	while (i >= 0)
		ft_remp_smaj_right_preci_two(str, &i, param);
}

void		ft_remp_smaj_right_bis(int *str, int *tmp, int i, t_param param)
{
	int			j;
	static int	k = 0;

	j = 0;
	k++;
	if (k == 3)
		k = 1;
	if (k == 2 && (int)param.width >= param.precision)
	{
		ft_call_two(str, tmp);
		return ;
	}
	if ((int)param.width >= param.precision)
		ft_remp_smaj_right_width(str, tmp, i, param);
	else
		ft_remp_smaj_right_preci(str, tmp, i, param);
	if (param.precision == 0)
	{
		while (j < (int)param.width)
			if (ft_is_in_at(param.flags, '0', 5))
				str[j++] = '0';
			else
				str[j++] = ' ';
		str[j] = '\0';
	}
}
