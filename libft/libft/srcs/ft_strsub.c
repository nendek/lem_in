/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:10:03 by pnardozi          #+#    #+#             */
/*   Updated: 2017/11/12 18:04:01 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*p;

	if (!(p = ft_strnew(len)))
		return (NULL);
	if (s)
	{
		while (start--)
			s++;
		ft_strncpy(p, s, len);
		p[len] = '\0';
	}
	return (p);
}
