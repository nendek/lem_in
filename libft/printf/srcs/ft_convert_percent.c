/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:30:00 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:30:00 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_remp_percent_left(char *str, int i)
{
	int		j;

	j = 1;
	while (j < i)
		str[j++] = ' ';
}

static void	ft_remp_percent_right(char *str, int i, t_param param)
{
	int		j;

	j = 0;
	while (j < i)
	{
		if (ft_is_in_at(param.flags, '0', 5))
			str[j++] = '0';
		else
			str[j++] = ' ';
	}
	str[--j] = '%';
}

static char	*ft_flags_percent(char *str, t_param param)
{
	int		i;
	char	*tmp;

	if (!(tmp = ft_strdup(str)))
		return (NULL);
	i = ft_strlen(str);
	if (i < (int)param.width)
		i = (int)param.width;
	free(str);
	if (!(str = ft_strnew(i)))
		return (NULL);
	if (!(ft_strcpy_p(str, tmp)))
		return (NULL);
	if (ft_is_in_at(param.flags, '-', 5))
		ft_remp_percent_left(str, i);
	else
		ft_remp_percent_right(str, i, param);
	free(tmp);
	return (str);
}

int			*ft_convert_percent(va_list *ap, t_param param)
{
	char	*str;
	int		*ret;

	if (param.precision < -2 && (!ap))
		return (NULL);
	if (!(str = ft_strnew(1)))
		return (NULL);
	str[0] = '%';
	if (!(str = ft_flags_percent(str, param)))
		return (NULL);
	if (!(ret = ft_ctoi(str)))
		return (NULL);
	free(str);
	return (ret);
}
