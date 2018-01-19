/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:00:20 by pnardozi          #+#    #+#             */
/*   Updated: 2017/11/12 17:47:30 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*p;
	unsigned char	*q;

	i = 0;
	p = (unsigned char*)s1;
	q = (unsigned char*)s2;
	while (i < (unsigned int)n)
	{
		if (p[i] != q[i])
			return ((unsigned int)(p[i] - q[i]));
		i++;
	}
	return (0);
}
