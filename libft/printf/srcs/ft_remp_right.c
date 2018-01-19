/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remp_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:32:02 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/17 14:55:08 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_remp_right_birm(long long var, int j, char *str, char *param)
{
	if (var < 0)
		str[j++] = '0';
	while (j > 0)
		str[j--] = '0';
	if (((ft_is_in_at(param, '+', 5)) && var >= 0))
		str[j] = '+';
	else if (var < 0)
		str[j] = '-';
	else if (ft_is_in_at(param, ' ', 5))
		str[j] = ' ';
	else
		str[j] = '0';
}

static void	ft_remp_right_preci_two(char *str, t_param param, int i, int j)
{
	while (i >= 0 && j < (int)param.width)
	{
		if (str[i] != '-')
			str[i--] = ' ';
		param.width--;
	}
}

static void	ft_remp_right_preci(char *str, t_param param, long long var)
{
	int		i;
	int		j;

	j = param.precision;
	i = 0;
	while (str[i] != '\0')
		i++;
	i--;
	while (ft_isdigit(str[i]) == 1 && i >= 0 && param.precision > 0)
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
	if (ft_is_in_at(param.flags, '+', 5))
		str[i--] = '+';
	if (var < 0 && str[i] == ' ')
		str[i--] = '-';
	ft_remp_right_preci_two(str, param, i, j);
}

static void	ft_remp_right_two(char *str, t_param param, long long var)
{
	int		i;

	i = 0;
	if (param.precision >= (int)param.width \
			|| param.precision >= ft_count_var(var))
		ft_remp_right_preci(str, param, var);
	if (param.precision <= ft_count_var(var) &&\
		ft_is_in_at(param.flags, '0', 5)\
			&& param.precision >= 0 && (ft_is_in_at(param.flags, '+', 5) == 0))
		while (str[i] == '0' && str[i] != '\0')
			str[i++] = ' ';
	i = 0;
	if (var == 0 && param.precision == 0)
		while (str[i] != '\0')
			str[i++] = ' ';
}

void		ft_remp_right(char *str, long long var, int i, t_param param)
{
	char	*ret;
	int		j;
	int		k;

	j = i;
	k = 0;
	if (!(ret = ft_long_itoa(var)))
		return ;
	while (ret[k] != '\0')
		k++;
	while (k >= 0)
		str[j--] = ret[k--];
	free(ret);
	if (ft_is_in_at(param.flags, '0', 5) && param.width > 0)
		ft_remp_right_birm(var, j, str, param.flags);
	else
	{
		if (((ft_is_in_at(param.flags, '+', 5)) && var >= 0))
			str[j--] = '+';
		while (j >= 0)
			str[j--] = ' ';
	}
	ft_remp_right_two(str, param, var);
}
