/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 11:43:07 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 11:43:09 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_one(int d)
{
	write(1, &d, 1);
	return (1);
}

static int	ft_two(int d)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	i = d >> 8;
	j = d << 8;
	j = j >> 8;
	write(1, &i, 1);
	write(1, &j, 1);
	return (2);
}

static int	ft_three(int d)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	i = d >> 16;
	j = d << 8;
	j = j >> 16;
	k = d << 16;
	k = k >> 16;
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
	return (3);
}

static int	ft_four(int d)
{
	int		i;
	int		j;
	int		k;
	int		l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	i = d >> 24;
	j = d << 8;
	j = j >> 24;
	k = d << 16;
	k = k >> 24;
	l = d << 24;
	l = l >> 24;
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
	write(1, &l, 1);
	return (4);
}

int			ft_wputchar(int c)
{
	unsigned int	d;

	d = (unsigned int)c;
	if (d < 256)
		return (ft_one(d));
	else if (d <= 57279)
		return (ft_two(d));
	else if (d <= 15712191)
		return (ft_three(d));
	else if (d <= 4103061439)
		return (ft_four(d));
	return (1);
}
