/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countsizeword.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:14:56 by pnardozi          #+#    #+#             */
/*   Updated: 2017/11/14 15:24:32 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_countsizeword(char const *s, char c, int *tab)
{
	int	i;
	int	size;
	int j;

	i = 0;
	size = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
			size++;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			tab[j] = size;
			size = 0;
			j++;
		}
		i++;
	}
}
