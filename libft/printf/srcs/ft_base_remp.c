/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_remp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:28:36 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:28:41 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_remp_base_left_two(char *str, t_param param,\
		unsigned long long int var)
{
	ft_remp_left_preci_two(str, param);
	if (var == 0 && param.precision == 0 && param.width > 0)
	{
		str[0] = '0';
		str[param.width--] = '\0';
		while (param.width > 0)
			str[param.width--] = ' ';
	}
}

void			ft_remp_base_left(char *str, \
		int i, t_param param, unsigned long long int var)
{
	char	*ret;
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (!(ret = ft_strdup(str)))
		return ;
	if (ft_is_in_at(param.flags, '#', 5) && var != 0)
		str[j++] = '0';
	while (ret[k] != '\0')
	{
		str[k + j] = ret[k];
		k++;
	}
	free(ret);
	j = k + j;
	while (j < i)
		str[j++] = ' ';
	str[j] = '\0';
	if (param.precision >= (int)param.width)
		ft_remp_left_preci(str);
	else
		ft_remp_base_left_two(str, param, var);
}

void			ft_remp_base_right(char *str, \
		int i, t_param param, unsigned long long int var)
{
	char	*ret;
	int		j;
	int		k;

	j = i;
	k = 0;
	if (!(ret = ft_strdup(str)))
		return ;
	while (ret[k] != '\0')
		k++;
	while (k >= 0)
		str[j--] = ret[k--];
	free(ret);
	if (ft_is_in_at(param.flags, '#', 5) && var != 0)
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
