/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 11:35:26 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 11:35:28 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_ctoi(char *str)
{
	int		*ret;
	int		j;
	int		i;

	i = 0;
	if (str)
	{
		while (str[i] != 0)
			i++;
		j = 0;
		if (!(ret = malloc(sizeof(int) * i + 1)))
			return (NULL);
		while (str[j] != '\0')
		{
			ret[j] = str[j];
			j++;
		}
		ret[j] = 0;
		return (ret);
	}
	return (NULL);
}
