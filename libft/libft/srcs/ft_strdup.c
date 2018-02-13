/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:25:52 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/13 18:03:57 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	if (s)
	{
		if (!(dest = ft_strnew(ft_strlen(s))))
			return (0);
		while (s[i] != '\0')
		{
			dest[i] = s[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (0);
}
