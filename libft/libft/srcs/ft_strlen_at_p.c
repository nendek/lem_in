/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_at_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:52:22 by pnardozi          #+#    #+#             */
/*   Updated: 2017/11/27 14:52:23 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_at_p(const char *s, char c)
{
	size_t size;

	size = 0;
	if (s)
	{
		while (*s++ != '\0' || *s != c)
			size++;
		return (size);
	}
	return (0);
}
