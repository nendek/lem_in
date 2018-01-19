/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:35:28 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:41:20 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_precision_bis(char *str, int *i)
{
	int		j;
	char	*ret;

	j = 0;
	(*i)++;
	while (ft_isdigit(str[*i]) == 1)
	{
		(*i)++;
		j++;
	}
	if (!(ret = ft_strnew(j)))
		return (0);
	(*i)--;
	j--;
	while (j >= 0)
		ret[j--] = str[(*i)--];
	return (ret);
}

int			ft_precision(char *str, int *i, t_param *param)
{
	char	*ret;

	while (str[*i] != '\0')
		(*i)++;
	while (*i >= 0)
	{
		if (str[*i] == '.')
		{
			if (!(ret = ft_precision_bis(str, i)))
				return (0);
			param->precision = ft_atoi(ret);
			free(ret);
			return (1);
		}
		(*i)--;
	}
	return (1);
}
