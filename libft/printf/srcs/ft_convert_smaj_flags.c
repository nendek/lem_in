/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_smaj_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:30:30 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:30:31 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		*ft_flags_smaj(int *str, t_param param)
{
	int		i;
	int		*tmp;

	tmp = ft_strdupw(str);
	i = 0;
	while (str[i] != 0)
		i++;
	if (param.precision > 0)
	{
		if ((int)param.width > param.precision)
			i = param.width;
		else
			i = param.precision;
	}
	else if ((int)param.width > i)
		i = param.width;
	if (!(str = malloc(sizeof(int) * i + 1)))
		return (NULL);
	str[i] = 0;
	if (ft_is_in_at(param.flags, '-', 5))
		ft_remp_smaj_left(str, tmp, i, param);
	else
		ft_remp_smaj_right(str, tmp, i, param);
	free(tmp);
	return (str);
}
