/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:15:31 by pnardozi          #+#    #+#             */
/*   Updated: 2017/11/12 16:24:25 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*d;
	char	*s;
	int		n;
	int		dlen;

	d = dest;
	s = (char*)src;
	n = (int)size;
	while (n-- != 0 && *d != 0)
		d++;
	dlen = d - dest;
	n = (int)size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(s));
	while (*s != 0)
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = 0;
	return (dlen + (s - src));
}
