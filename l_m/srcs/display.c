/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 11:27:44 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/13 17:40:32 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		lm_get_end(t_room **begin_list, t_room **end)
{
	t_room	*lst;

	lst = *begin_list;
	while (lst)
	{
		if (lst->start_end == 2)
		{
			*end = lst;
			break ;
		}
		lst = lst->next;
	}
}

static int		lm_count_lst(t_visit **begin_list)
{
	t_visit	*lst;
	int		i;

	i = 0;
	lst = *begin_list;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

static int		lm_move_ants(t_visit **lst_road, t_room *end_room,\
		t_room **lst_room, t_pos *index)
{
	char		*start;
	t_visit		*road1;
	t_visit		*road2;
	int			tmp;
	int			space;

	road2 = *lst_road;
	start = lm_search_s_e(lst_room, 1);
	space = 0;
	while (index->x != 1)
	{
		lm_move_ants2(index, &road1, &road2, &tmp);
		if (ft_strcmp(road1->name, end_room->name) == 0)
			lm_move_ants3(&space, &end_room, &road2);
		else if (ft_strcmp(road2->name, start) == 0 && road2->name_ant >= 1)
			lm_move_ants4(&space, &road1, &road2, index);
		else if (road1->name_ant == 0 && road2->name_ant != 0)
			lm_move_ants5(&space, &road1, &road2);
		road2 = *lst_road;
		index->x--;
	}
	ft_printf("\n");
	free(start);
	return (0);
}

int				lm_display(t_visit **lst_road, t_room **lst_room, int nb_ants)
{
	t_room		*room_end;
	t_pos		index;
	int			i;

	index.y = nb_ants;
	i = lm_count_lst(lst_road);
	lm_get_end(lst_room, &(room_end));
	while (room_end->ants != nb_ants)
	{
		index.x = i;
		lm_move_ants(lst_road, room_end, lst_room, &index);
	}
	return (1);
}
