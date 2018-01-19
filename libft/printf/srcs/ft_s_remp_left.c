/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_remp_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:32:20 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:48:17 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_remp_s_left_bis(int j, char *str, char *tmp, t_param param)
{
	while (j < param.precision && tmp[j] != '\0')
	{
		str[j] = tmp[j];
		if (tmp[0] == '\0')
			str[j] = ' ';
		j++;
	}
	while (j < (int)param.width)
		str[j++] = ' ';
}

void		ft_remp_s_left(char *str, char *tmp, int i, t_param param)
{
	int		j;

	j = 0;
	if (param.precision <= 0)
	{
		while (tmp[j] != '\0' && j < i)
		{
			str[j] = tmp[j];
			j++;
		}
		while (j < (int)param.width)
			str[j++] = ' ';
	}
	else
	{
		if (param.width == 0 && tmp[0] == 0)
			return ;
		ft_remp_s_left_bis(j, str, tmp, param);
	}
}

void		ft_remp_s_right(char *str, char *tmp, int i, t_param param)
{
	int		j;

	j = 0;
	if (param.precision < 0)
	{
		while (tmp[j] != '\0')
			j++;
		j--;
		i--;
		while (j >= 0)
		{
			str[i] = tmp[j];
			i--;
			j--;
		}
		while (i >= 0)
		{
			if (ft_is_in_at(param.flags, '0', 5))
				str[i--] = '0';
			else
				str[i--] = ' ';
		}
	}
	else
		ft_remp_s_right_bis(str, tmp, i, param);
}
