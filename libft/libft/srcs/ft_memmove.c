/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:10:56 by pnardozi          #+#    #+#             */
/*   Updated: 2017/11/12 15:53:01 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	size_t			i;

	i = 0;
	d = dest;
	if (dest < src)
		while (i != n)
		{
			*(unsigned char*)dest++ = *(unsigned char*)src++;
			i++;
		}
	else
		while (n-- > 0)
			((unsigned char*)dest)[n] = ((unsigned char*)src)[n];
	return (d);
}
