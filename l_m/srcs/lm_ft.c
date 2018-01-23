/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:32:35 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/23 16:21:56 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lm_check_int(long long nb, char *tmp)
{
	if (nb > INT_MAX || nb < INT_MIN)
	{
		ft_printf("Erreur: nommbre plus grand qu un int\n");
		free(tmp);
		return (0);
	}
	return (1);
}
