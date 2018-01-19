/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:44:54 by pnardozi          #+#    #+#             */
/*   Updated: 2017/11/12 17:11:43 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;

	if (s1 && s2)
	{
		p = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (!p)
			return (NULL);
		ft_strcpy(p, s1);
		ft_strcat(p, s2);
		return (p);
	}
	return (NULL);
}
