/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:30:09 by pnardozi          #+#    #+#             */
/*   Updated: 2017/11/12 16:44:05 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*str;

	if (size >= 2147483647)
		return (NULL);
	if (!(str = (unsigned char*)malloc(sizeof(unsigned char) * (size + 1))))
		return (NULL);
	ft_memset(str, 0, size);
	return (&str[0]);
}
