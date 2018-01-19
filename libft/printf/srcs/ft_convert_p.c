/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:29:51 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:29:52 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_diese_param(t_param *param)
{
	int		j;

	j = 0;
	while (j < 5)
	{
		if (param->flags[j] == '#')
			return ;
		if (param->flags[j] == 'R')
		{
			param->flags[j] = '#';
			return ;
		}
		j++;
	}
}

static char		*ft_flags_p(char *str, unsigned long long int var, \
		t_param param)
{
	int		i;
	char	*tmp;

	if (!(tmp = ft_strdup(str)))
		return (NULL);
	i = ft_strlen(str);
	if (i < (int)param.width)
		i = (int)param.width;
	if (i < param.precision)
		i = param.precision;
	if ((ft_is_in_at(param.flags, '#', 5)) &&\
			(i == (int)ft_strlen(str) || i == param.precision))
		i += 2;
	free(str);
	if (!(str = ft_strnew(i)))
		return (NULL);
	if (!(ft_strcpy_p(str, tmp)))
		return (NULL);
	if (ft_is_in_at(param.flags, '-', 5))
		ft_remp_hex_left(str, i, param, var);
	else
		ft_remp_hex_right(str, i, param, var);
	free(tmp);
	return (str);
}

static void		ft_replace_x(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != 'x')
		i++;
	if (str[i] == 'x')
		str[i] = '0';
	while (str[i] == '0' && i >= 0)
		i--;
	str[i + 2] = 'x';
}

int				*ft_convert_p(va_list *ap, t_param param)
{
	unsigned long long int	var;
	char					*str;
	int						*ret;

	str = 0;
	var = va_arg(*ap, unsigned long long int);
	ft_diese_param(&param);
	if (!(str = ft_base_hexa(var, param)))
		return (0);
	if (!(str = ft_flags_p(str, var, param)))
		return (NULL);
	ft_replace_x(str);
	if (!(ret = ft_ctoi(str)))
		return (NULL);
	free(str);
	return (ret);
}
