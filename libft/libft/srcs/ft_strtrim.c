/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:32:54 by pnardozi          #+#    #+#             */
/*   Updated: 2017/11/12 18:29:08 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*p;
	unsigned int	start;
	int				end;

	start = 0;
	if (s)
	{
		end = (int)ft_strlen(s) - 1;
		while ((s[start] == ' ' || s[start] == '\n' || \
					s[start] == '\t') && s[start])
			start++;
		while ((s[end] == ' ' || s[end] == '\n' || \
					s[end] == '\t') && s[end] && end > (int)start)
			end--;
		p = ft_strsub(s, start, (end - start + 1));
		if (!p)
			return (NULL);
		else
			return (p);
	}
	return (NULL);
}
