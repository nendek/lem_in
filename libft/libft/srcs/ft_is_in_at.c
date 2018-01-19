/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 14:31:03 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/17 14:31:05 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_is_in_at(char *str, char c, int length)
{
	int i;

	i = 0;
	while (i < length)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
