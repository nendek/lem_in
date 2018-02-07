/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 11:27:44 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/07 17:40:30 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lm_get_end(t_room **begin_list, t_room **end)
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

int		lm_count_lst(t_visit **begin_list)
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

int		lm_move_ants(t_visit **lst_road, t_room *end_room, int i, t_room **lst_room)
{
	char 		*start;
	t_visit		*road1;
	t_visit		*road2;
	int			tmp;

	road2 = *lst_road;
	start = lm_search_s_e(lst_room, 1);
	while (i != 1)
	{
		tmp = 1;
		while (tmp < i - 1 && road2)
		{
			road2 = road2->next;
			tmp++;
		}
		road1 = road2->next;
		//dprintf(1, "road1 = %s, road2 = %s\n", road1->name, road2->name);
		if (ft_strcmp(road1->name, end_room->name) == 0)
		{
			if (road2->name_ant != 0)
			{
				ft_printf("L%d-%s ", road2->name_ant, end_room->name);
				road2->name_ant = 0;
				end_room->ants++;
			}
		}
		else if (ft_strcmp(road2->name, start) == 0 && road2->name_ant >= 1)
		{
			if (road1->name_ant == 0 && road2->name != 0)
			{
				ft_printf("L%d-%s ", road2->name_ant, road1->name);
				road1->name_ant = road2->name_ant;
				road2->name_ant--;
			}
		}
		else if (road1->name_ant == 0 && road2->name_ant != 0)
		{
			ft_printf("L%d-%s ", road2->name_ant, road1->name);
			road1->name_ant = road2->name_ant;
			road2->name_ant = 0;
		}
		road2 = *lst_road;
		i--;
	}
	ft_printf("\n");
	return (1);
}

int		lm_display(t_visit **lst_road, t_room **lst_room, int nb_ants)
{
	t_room		*room_end;
	int			i;

	i = nb_ants;


	i = lm_count_lst(lst_road);
	lm_get_end(lst_room, &(room_end));
	while (room_end->ants != nb_ants)
		lm_move_ants(lst_road, room_end, i, lst_room);

	return (1);
}
