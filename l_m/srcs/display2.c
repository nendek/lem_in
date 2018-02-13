/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:36:18 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/13 17:39:08 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lm_move_ants2(t_pos *index, t_visit **road1, t_visit **road2, int *tmp)
{
	*tmp = 1;
	while (*tmp < index->x - 1 && *road2)
	{
		*road2 = (*road2)->next;
		*tmp += 1;
	}
	*road1 = (*road2)->next;
}

void	lm_move_ants3(int *space, t_room **end_room, t_visit **road2)
{
	if ((*road2)->name_ant != 0)
	{
		if (*space == 0)
			ft_printf("L%d-%s", (*road2)->name_ant, (*end_room)->name);
		else
			ft_printf(" L%d-%s", (*road2)->name_ant, (*end_room)->name);
		*space = 1;
		(*road2)->name_ant = 0;
		(*end_room)->ants++;
	}
}

void	lm_move_ants4(int *space, t_visit **road1, t_visit **road2,\
		t_pos *index)
{
	if ((*road1)->name_ant == 0 && (*road2)->name != 0)
	{
		if (*space == 0)
			ft_printf("L%d-%s", (*index).y, (*road1)->name);
		else
			ft_printf(" L%d-%s", (*index).y, (*road1)->name);
		*space = 1;
		(*road1)->name_ant = (*index).y;
		(*road2)->name_ant--;
		(*index).y -= 1;
	}
}

void	lm_move_ants5(int *space, t_visit **road1, t_visit **road2)
{
	if (*space == 0)
		ft_printf("L%d-%s", (*road2)->name_ant, (*road1)->name);
	else
		ft_printf(" L%d-%s", (*road2)->name_ant, (*road1)->name);
	*space = 1;
	(*road1)->name_ant = (*road2)->name_ant;
	(*road2)->name_ant = 0;
}
