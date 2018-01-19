/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:06:48 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 13:10:38 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_verif_byte(wchar_t i, int *tmp)
{
	if (i <= 1114111)
		return (i);
	*tmp = i;
	*tmp = *tmp << 16;
	*tmp = *tmp >> 24;
	return (*tmp);
}

int			*ft_wctoi(wchar_t *str)
{
	int		*ret;
	int		i;
	int		tmp;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(ft_verif_byte(str[i], &tmp)))
			break ;
		i++;
	}
	if (!(ret = malloc(sizeof(int) * i + 1)))
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (!(ft_verif_byte(str[i], &tmp)))
			break ;
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
