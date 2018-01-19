/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:43:41 by pnardozi          #+#    #+#             */
/*   Updated: 2017/11/12 18:15:11 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*p;
	unsigned char	*q;

	p = (unsigned char*)s1;
	q = (unsigned char*)s2;
	i = 0;
	while (p[i] != '\0' && q[i] != '\0' && p[i] == q[i])
		i++;
	return ((unsigned int)(p[i] - q[i]));
}
