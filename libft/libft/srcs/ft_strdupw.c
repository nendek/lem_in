/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 14:05:12 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 14:07:16 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_strdupw(int *str)
{
	int		i;
	int		*ret;

	i = 0;
	while (str[i] != 0)
		i++;
	if (!(ret = malloc(sizeof(int) * i + 1)))
		return (NULL);
	i = 0;
	while (str[i] != 0)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
