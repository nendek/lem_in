/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:29:42 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/17 14:47:05 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char						*ft_base_octal(unsigned long long int nb,\
		t_param param)
{
	unsigned long long int	tmp;
	int						i;
	char					*str;

	i = 0;
	tmp = nb;
	while (tmp != 0)
	{
		tmp /= 8;
		i++;
	}
	if (nb == 0 && param.precision != 0)
		i = 1;
	if (!(str = ft_strnew(i)))
		return (0);
	if (nb == 0 && param.precision != 0)
		str[--i] = '0';
	while (nb != 0)
	{
		str[--i] = g_base_oct[nb % 8];
		nb /= 8;
	}
	return (str);
}

static unsigned long long int	var_modifier_o(unsigned long long int var, \
		t_param param)
{
	unsigned long long int ret;

	ret = var;
	if (param.modifier[0] == 'h')
		return ((unsigned short)ret);
	else if (param.modifier[0] == 'g')
		return ((unsigned char)ret);
	else if (param.modifier[0] == 'l')
		return ((unsigned long long int)ret);
	else if (param.modifier[0] == 'm')
		return ((long long)ret);
	else if (param.modifier[0] == 'j')
		if (var > 0)
			return (ret);
		else
			return (ret);
	else if (param.modifier[0] == 'z')
		return ((size_t)ret);
	else
		return ((unsigned int)ret);
}

static char						*ft_flags_o(char *str, \
		unsigned long long int var, t_param param)
{
	int		i;
	char	*tmp;

	tmp = ft_strdup(str);
	i = ft_strlen(str);
	if (i < (int)param.width)
		i = (int)param.width;
	if (i < param.precision)
		i = param.precision;
	if (var == 0 && param.precision == 0 && param.width == 0 \
			&& (ft_is_in_at(param.flags, '#', 5) == 0))
		return (str);
	if ((var != 0 && (ft_is_in_at(param.flags, '#', 5)) &&\
				i == (int)ft_strlen(str)) || (var == 0 &&\
				ft_is_in_at(param.flags, '#', 5) && param.precision == 0))
		i++;
	free(str);
	if (!(str = ft_strnew(i)))
		return (NULL);
	ft_strcpy_p(str, tmp);
	ft_is_in_at(param.flags, '-', 5) ? ft_remp_base_left(str, i, param, var)\
		: ft_remp_base_right(str, i, param, var);
	free(tmp);
	return (str);
}

int								*ft_convert_o(va_list *ap, t_param param)
{
	unsigned long long int	var;
	char					*str;
	int						*ret;

	str = NULL;
	if (param.precision < -2)
		return (0);
	var = va_arg(*ap, unsigned long long int);
	var = var_modifier_o(var, param);
	str = ft_base_octal(var, param);
	str = ft_flags_o(str, var, param);
	if (!(ret = ft_ctoi(str)))
		return (0);
	free(str);
	return (ret);
}

int								*ft_convert_omaj(va_list *ap, t_param param)
{
	unsigned long long int	var;
	char					*str;
	int						*ret;

	str = NULL;
	if (param.precision < -2)
		return (0);
	var = va_arg(*ap, unsigned long long int);
	str = ft_base_octal(var, param);
	str = ft_flags_o(str, var, param);
	if (!(ret = ft_ctoi(str)))
		return (0);
	free(str);
	return (ret);
}
