/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_modifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:35:20 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:35:20 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_modifier_pnt(int *i, int *j, t_param *param)
{
	param->modifier[0] = 'j';
	(*i)++;
	*j = 6;
}

void	ft_modifier_car(int *i, int *j, t_param *param)
{
	param->modifier[0] = 'z';
	(*i)++;
	*j = 4;
}

void	ft_modifier_ter(char *str, int *i, int *j, t_param *param)
{
	if (str[*i + 1] == 'l' && *j < 5)
	{
		param->modifier[0] = 'm';
		*i += 2;
		*j = 5;
	}
	else if (*j < 3)
	{
		param->modifier[0] = 'l';
		(*i)++;
		*j = 3;
	}
}

void	ft_modifier_bis(char *str, int *i, int *j, t_param *param)
{
	if (str[*i + 1] == 'h' && *j < 1)
	{
		param->modifier[0] = 'g';
		*i += 2;
		*j = 1;
	}
	else
	{
		param->modifier[0] = 'h';
		(*i) += 1;
		*j = 2;
	}
}
