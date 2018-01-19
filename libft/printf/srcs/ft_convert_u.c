/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:30:49 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:53:37 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long int	var_unsigned_maj_modifier(\
		unsigned long long int var, t_param param)
{
	unsigned long long int ret;

	ret = var;
	if (param.modifier[0] == 'h')
		return ((unsigned long int)ret);
	else if (param.modifier[0] == 'g')
		return ((unsigned long)ret);
	else if (param.modifier[0] == 'l')
		return ((unsigned long long int)ret);
	else if (param.modifier[0] == 'm')
		return ((unsigned long long)ret);
	else if (param.modifier[0] == 'j')
		if (var > 0)
			return (ret);
		else
			return (ret);
	else if (param.modifier[0] == 'z')
		return ((size_t)ret);
	else
		return ((unsigned long int)ret);
}

static unsigned long long int	var_unsigned_modifier(\
		unsigned long long int var, t_param param)
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
		return ((unsigned long long int)ret);
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

static char						*ft_flags_u(unsigned long long int var, \
		t_param param)
{
	int		i;
	char	*str;

	str = NULL;
	i = ft_count_unsigned_var(var);
	if (i < (int)param.width)
		i = (int)param.width;
	if (i < param.precision)
		i = param.precision;
	if (var == 0 && param.precision == 0 && param.width == 0)
		return (str);
	if (!(str = ft_strnew(i)))
		return (NULL);
	if (ft_is_in_at(param.flags, '-', 5))
		ft_remp_unsigned_left(str, var, i, param);
	else
		ft_remp_unsigned_right(str, var, i, param);
	return (str);
}

int								*ft_convert_u(va_list *ap, t_param param)
{
	unsigned long long int	var;
	char					*str;
	int						*ret;

	if (param.precision < -2)
		return (0);
	var = va_arg(*ap, unsigned long long int);
	var = var_unsigned_modifier(var, param);
	str = ft_flags_u(var, param);
	if (!(ret = ft_ctoi(str)))
		return (NULL);
	free(str);
	return (ret);
}

int								*ft_convert_umaj(va_list *ap, t_param param)
{
	char					*str;
	int						*ret;
	unsigned long long int	var;

	if (param.precision < -2)
		return (0);
	var = va_arg(*ap, unsigned long long int);
	var = var_unsigned_maj_modifier(var, param);
	str = ft_flags_u(var, param);
	if (!(ret = ft_ctoi(str)))
		return (NULL);
	free(str);
	return (ret);
}
