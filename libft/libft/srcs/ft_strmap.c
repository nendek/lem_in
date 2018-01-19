/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:04:00 by pnardozi          #+#    #+#             */
/*   Updated: 2017/11/12 17:58:41 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			p[i] = (*f)(s[i]);
			i++;
		}
		return (p);
	}
	return (NULL);
}
