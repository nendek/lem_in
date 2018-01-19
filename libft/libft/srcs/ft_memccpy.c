/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:32:48 by pnardozi          #+#    #+#             */
/*   Updated: 2017/11/12 17:46:03 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = dest;
	s = (void*)src;
	while (n--)
	{
		if (*s == (unsigned char)c)
		{
			*d++ = *s++;
			return (d);
		}
		*d++ = *s++;
	}
	return (NULL);
}
