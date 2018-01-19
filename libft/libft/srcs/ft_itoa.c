/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:44:13 by pnardozi          #+#    #+#             */
/*   Updated: 2017/11/12 17:36:07 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long	size;
	char	*p;
	long	n_long;
	int		sign;

	n_long = n;
	sign = 0;
	if (n_long < 0)
		sign = 1;
	size = ft_nbdigit(n_long);
	if (!(p = ft_strnew(size)))
		return (NULL);
	if (n_long < 0)
		n_long = -n_long;
	size--;
	while (size >= 0)
	{
		p[size] = (n_long % 10) + '0';
		size--;
		n_long /= 10;
	}
	if (sign)
		p[0] = '-';
	return (p);
}
