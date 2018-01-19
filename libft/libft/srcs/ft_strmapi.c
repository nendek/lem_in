/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:56:50 by pnardozi          #+#    #+#             */
/*   Updated: 2017/11/12 18:00:28 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	int		i;

	i = 0;
	if (s && f)
	{
		p = ft_strnew(ft_strlen(s));
		if (!p)
			return (NULL);
		while (s[i] != '\0')
		{
			p[i] = (*f)(i, s[i]);
			i++;
		}
		return (p);
	}
	return (NULL);
}
