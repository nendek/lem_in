/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:32:35 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/22 17:36:34 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lm_check_int(long long nb, char *tmp)
{
	if (nb > INT_MAX || nb < INT_MIN)
	{
		free(tmp);
		return (0);
	}
	return (1);
}
