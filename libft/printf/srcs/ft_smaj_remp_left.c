/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smaj_remp_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:32:48 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:48:02 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_remp_smaj_left_bis(int j, int *str, int *tmp, t_param param)
{
	while (j < param.precision && tmp[j] != 0)
	{
		str[j] = tmp[j];
		if (tmp[0] == '\0')
			str[j] = ' ';
		j++;
	}
	while (j < (int)param.width)
		str[j++] = ' ';
}

void		ft_call_two(int *str, int *tmp)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (tmp[j] != '\0')
	{
		if (tmp[j] >= 49792 && tmp[j] <= 57278)
			i++;
		else if (tmp[j] >= 14721152 && tmp[j] <= 15712191)
			i += 2;
		else if (tmp[j] < -1114111)
			i += 3;
		j++;
	}
	j = 0;
	while (tmp[j] != '\0')
	{
		str[j] = tmp[j + i];
		j++;
	}
}

void		ft_remp_smaj_left(int *str, int *tmp, int i, t_param param)
{
	int		j;

	j = 0;
	if (param.precision < 0)
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
		ft_remp_smaj_left_bis(j, str, tmp, param);
	}
}

void		ft_remp_smaj_right(int *str, int *tmp, int i, t_param param)
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
		ft_remp_smaj_right_bis(str, tmp, i, param);
}
