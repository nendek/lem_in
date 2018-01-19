/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:09:38 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/19 14:09:41 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_push(int *pile_dst, int *pile_src, int *i_dst, int *i_src)
{
	if (*i_src >= 0)
	{
		*i_dst += 1;
		pile_dst[*i_dst] = pile_src[*i_src];
		*i_src -= 1;
	}
}
