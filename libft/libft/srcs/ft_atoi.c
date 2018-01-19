/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:42:45 by pnardozi          #+#    #+#             */
/*   Updated: 2017/11/12 17:30:55 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_over(const char *str)
{
	int sign;
	int i;

	i = 0;
	sign = -1;
	while (*str != '\0' && ft_iswp(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = 0;
		str++;
	}
	while (ft_isdigit(*str) && *str != '\0')
	{
		i++;
		str++;
	}
	if (i >= 19)
		return (sign);
	return (1);
}

int				ft_atoi(const char *str)
{
	int res;
	int sign;

	sign = 1;
	res = 0;
	while (*str != '\0' && ft_iswp(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (ft_isdigit(*str) && *str != '\0')
	{
		res = res * 10 + sign * (*str - '0');
		str++;
	}
	if (ft_over(str) == 0 || ft_over(str) == -1)
		return (ft_over(&str[0]));
	return ((int)res);
}
