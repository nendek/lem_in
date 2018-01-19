/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:59:18 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 16:00:37 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoc(int *str)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i] != 0)
		i++;
	if (!(ret = ft_strnew(i)))
		return (NULL);
	i = 0;
	while (str[i] != 0)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
