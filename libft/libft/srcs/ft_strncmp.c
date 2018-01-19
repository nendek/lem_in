/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:30:09 by pnardozi          #+#    #+#             */
/*   Updated: 2017/11/12 18:15:54 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*p;
	unsigned char	*q;

	if (n == 0)
		return (0);
	p = (unsigned char*)s1;
	q = (unsigned char*)s2;
	i = 0;
	while (p[i] != '\0' && q[i] != '\0' && p[i] == q[i] && --n)
		i++;
	return ((unsigned int)(p[i] - q[i]));
}
