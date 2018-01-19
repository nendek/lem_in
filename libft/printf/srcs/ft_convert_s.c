/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:30:09 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:30:10 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_flags_s(char *str, t_param param)
{
	int		i;
	char	*tmp;

	tmp = ft_strdup(str);
	i = ft_strlen(str);
	if (param.precision > 0)
	{
		if ((int)param.width > param.precision)
			i = param.width;
		else
			i = param.precision;
	}
	else if ((int)param.width > i)
		i = param.width;
	if (!(str = ft_strnew(i)))
		return (NULL);
	if (ft_is_in_at(param.flags, '-', 5))
		ft_remp_s_left(str, tmp, i, param);
	else
		ft_remp_s_right(str, tmp, i, param);
	free(tmp);
	return (str);
}

static char	*ft_string_one(t_param param)
{
	int		i;
	char	*str;
	int		j;
	int		k;

	k = 0;
	i = 0;
	if (i < (int)param.width)
		i = (int)param.width;
	if (i < param.precision)
		i = param.precision;
	if (!(str = ft_strnew(i)))
		return (NULL);
	(param.precision >= 0) ? (j = (int)param.width - param.precision) :\
						(j = param.width - 6);
	while (k < j && k < i)
		if (ft_is_in_at(param.flags, '0', 5))
			str[k++] = '0';
		else
			str[k++] = ' ';
	j = 0;
	while (k < i)
		str[k++] = g_null[j++];
	return (str);
}

static char	*ft_string_two(t_param param)
{
	t_norme	i;
	char	*str;
	int		k;

	k = 0;
	i.i = 0;
	if (i.i < (int)param.width)
		i.i = (int)param.width;
	if (i.i < param.precision)
		i.i = param.precision;
	if (!(str = ft_strnew(i.i)))
		return (NULL);
	(param.precision == -1) ? (i.j = 7) :\
				(i.j = param.precision);
	while (k < i.j && k < i.i && k < 6)
	{
		str[k] = g_null[k];
		k++;
	}
	while (k < i.i)
		if (ft_is_in_at(param.flags, '0', 5))
			str[k++] = '0';
		else
			str[k++] = ' ';
	return (str);
}

static char	*ft_string_null(t_param param)
{
	if (ft_is_in_at(param.flags, '-', 5))
		return (ft_string_two(param));
	else
		return (ft_string_one(param));
}

int			*ft_convert_s(va_list *ap, t_param param)
{
	char	*str;
	int		*ret;

	if (param.precision < -2)
		return (0);
	if (param.modifier[0] == 'l')
		return (ft_convert_smaj(ap, param));
	str = (char*)va_arg(*ap, int*);
	if (str == NULL && ((param.precision >= 0) || param.width >= 7))
	{
		if (!(str = ft_string_null(param)))
			return (NULL);
	}
	else if (str == NULL)
		return (NULL);
	else
		str = ft_flags_s(str, param);
	if (!(ret = ft_ctoi(str)))
		return (NULL);
	free(str);
	return (ret);
}
