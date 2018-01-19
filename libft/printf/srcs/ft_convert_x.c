/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:31:00 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:51:00 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long int	var_modifier_x(unsigned long long int var, \
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

static void						ft_flags_two(char *str,\
		unsigned long long int var, t_param param, int i)
{
	if (ft_is_in_at(param.flags, '-', 5))
		ft_remp_hex_left(str, i, param, var);
	else
		ft_remp_hex_right(str, i, param, var);
}

static char						*ft_flags_x(char *str,\
		unsigned long long int var, t_param param)
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
	if (var == 0 && param.precision == 0 && param.width == 0 \
			&& (ft_is_in_at(param.flags, '#', 5)))
		return (str);
	if (var != 0 && (ft_is_in_at(param.flags, '#', 5))\
			&& (i == (int)ft_strlen(str) || i == param.precision))
		i += 2;
	free(str);
	if (!(str = ft_strnew(i)))
		return (NULL);
	if (!(ft_strcpy_p(str, tmp)))
		return (NULL);
	free(tmp);
	ft_flags_two(str, var, param, i);
	return (str);
}

int								*ft_convert_x(va_list *ap, t_param param)
{
	unsigned long long int	var;
	char					*str;
	int						*ret;

	str = NULL;
	if (param.precision < -2)
		return (0);
	var = va_arg(*ap, unsigned long long int);
	var = var_modifier_x(var, param);
	if (!(str = ft_base_hexa(var, param)))
		return (NULL);
	if (!(str = ft_flags_x(str, var, param)))
		return (NULL);
	if (!(ret = ft_ctoi(str)))
		return (NULL);
	free(str);
	return (ret);
}

int								*ft_convert_xmaj(va_list *ap, t_param param)
{
	int		*str;
	char	*ret;
	int		i;

	str = NULL;
	i = 0;
	str = ft_convert_x(ap, param);
	while (str[i] != 0)
		i++;
	if (!(ret = malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (str[i] != 0)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	ft_strcap(ret);
	free(str);
	if (!(str = ft_ctoi(ret)))
		return (NULL);
	free(ret);
	return (str);
}
