/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_remp2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:34:06 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/17 14:55:37 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_remp_unsigned_left(char *str, unsigned long long int var, \
		int i, t_param param)
{
	char	*ret;
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (!(ret = ft_unsigned_itoa(var)))
		return ;
	if (ft_is_in_at(param.flags, '#', 5) &&\
			(param.conv == 'o' || param.conv == 'O'))
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
	else if (param.precision < (int)param.width)
		ft_remp_left_preci_two(str, param);
}
