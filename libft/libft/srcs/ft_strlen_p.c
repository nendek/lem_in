/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:52:34 by pnardozi          #+#    #+#             */
/*   Updated: 2017/11/27 14:52:37 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_p(const char *s)
{
	size_t size;

	size = 0;
	if (s)
	{
		while (*s++ != '\0')
			size++;
		return (size);
	}
	return (0);
}
