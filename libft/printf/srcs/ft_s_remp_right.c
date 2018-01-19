/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_remp_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:32:29 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:46:57 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_remp_s_right_widht_two(char *str, int *i, t_param param)
{
	if (ft_is_in_at(param.flags, '0', 5))
		str[(*i)--] = '0';
	else
		str[(*i)--] = ' ';
}

static void	ft_remp_s_right_width(char *str, char *tmp, int i, t_param param)
{
	int		j;

	j = 0;
	if (param.width == 0 && tmp[0] == 0)
		return ;
	i--;
	j = ((int)ft_strlen(tmp) >= param.precision) ?\
		param.precision - 1 : (int)ft_strlen(tmp) - 1;
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
		ft_remp_s_right_widht_two(str, &i, param);
}

static void	ft_remp_s_right_preci_two(char *str, char *tmp, t_param param,\
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

static void	ft_remp_s_right_preci(char *str, char *tmp, t_param param)
{
	int		j;
	int		k;

	k = (param.width > ft_strlen(tmp)) ?\
		(int)param.width - 1 : (int)ft_strlen(tmp) - 1;
	if (param.width == 0 && tmp[0] == 0)
		return ;
	j = (int)ft_strlen(tmp) - 1;
	if ((int)ft_strlen(tmp) <= param.precision)
	{
		while (tmp[j] != '\0')
		{
			str[k] = tmp[j];
			j--;
			k--;
			param.width--;
		}
		while (k >= 0)
			ft_remp_s_right_widht_two(str, &k, param);
	}
	else
		ft_remp_s_right_preci_two(str, tmp, param, j);
}

void		ft_remp_s_right_bis(char *str, char *tmp, int i, t_param param)
{
	int		j;

	j = 0;
	if ((int)param.width >= param.precision)
		ft_remp_s_right_width(str, tmp, i, param);
	else
		ft_remp_s_right_preci(str, tmp, param);
	if (param.precision == 0)
	{
		while (j < (int)param.width)
		{
			if (ft_is_in_at(param.flags, '0', 5))
				str[j] = '0';
			else
				str[j] = ' ';
			j++;
		}
		str[j] = '\0';
	}
}
