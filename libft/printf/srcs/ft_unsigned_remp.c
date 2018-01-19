/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_remp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:33:55 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:44:52 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_remp_unsigned_right_preci2(char *str,\
		t_param param, int i, int j)
{
	while (i >= 0 && j < (int)param.width)
	{
		str[i--] = ' ';
		param.width--;
	}
}

void		ft_remp_unsigned_right_birm(int j, char *str)
{
	while (j > 0)
		str[j--] = '0';
	str[j] = '0';
}

void		ft_remp_unsigned_right_preci(char *str, t_param param)
{
	int		i;
	int		j;

	i = 0;
	j = param.precision;
	while (str[i] != '\0')
		i++;
	i--;
	while (str[i] != ' ' && i >= 0 && param.precision > 0)
	{
		i--;
		param.precision--;
	}
	while (param.precision > 0 && i >= 0)
	{
		str[i] = '0';
		i--;
		param.precision--;
	}
	if (param.precision == 0 && i == 0)
		i--;
	ft_remp_unsigned_right_preci2(str, param, i, j);
}

void		ft_remp_unsigned_right_bis(char *str, \
		t_param param, unsigned long long int var)
{
	int		i;

	i = 0;
	if (param.precision >= (int)param.width \
			|| param.precision > ft_count_var(var))
		ft_remp_unsigned_right_preci(str, param);
	if (var == 0 && param.precision == 0)
		while (str[i] != '\0')
			str[i++] = ' ';
	if (var == 0 && param.precision == 0 && ft_is_in_at(param.flags, '#', 5))
	{
		if (param.width > 0)
			str[param.width - 1] = '0';
		else
			str[0] = '0';
	}
	if (var == 0 && param.precision == -1 && param.width > 1\
			&& (param.conv == 'o' || param.conv == 'O'))
	{
		if (ft_is_in_at(param.flags, '0', 5))
			str[0] = '0';
		else
			str[0] = ' ';
	}
}

void		ft_remp_unsigned_right(char *str, unsigned long long int var, \
		int i, t_param param)
{
	char	*ret;
	int		j;
	int		k;

	j = i;
	k = 0;
	if (!(ret = ft_unsigned_itoa(var)))
		return ;
	while (ret[k] != '\0')
		k++;
	while (k >= 0)
		str[j--] = ret[k--];
	free(ret);
	if (ft_is_in_at(param.flags, '#', 5))
		str[j--] = '0';
	if (ft_is_in_at(param.flags, '0', 5) && param.precision == -1)
		ft_remp_unsigned_right_birm(j, str);
	else
	{
		while (j >= 0)
			str[j--] = ' ';
	}
	ft_remp_unsigned_right_bis(str, param, var);
}
