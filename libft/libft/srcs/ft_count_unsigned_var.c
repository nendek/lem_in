/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_unsigned_var.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 11:34:58 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 11:35:02 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_count_unsigned_var(unsigned long int var)
{
	int		i;

	i = 0;
	if (var == 0)
		return (1);
	while (var != 0)
	{
		var /= 10;
		i++;
	}
	return (i);
}
