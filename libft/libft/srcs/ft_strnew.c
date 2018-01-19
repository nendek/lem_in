/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:37:23 by pnardozi          #+#    #+#             */
/*   Updated: 2017/11/12 16:47:04 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	unsigned char	*str;

	if (!(str = ft_memalloc(size)))
		return (NULL);
	str[size] = '\0';
	return ((char*)&str[0]);
}
