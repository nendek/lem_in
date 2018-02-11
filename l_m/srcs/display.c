/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 11:27:44 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/11 15:16:19 by pnardozi         ###   ########.fr       */
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

int		lm_move_ants(t_visit **lst_road, t_room *end_room, int i, t_room **lst_room, int *nb_ants)
{
	char 		*start;
	t_visit		*road1;
	t_visit		*road2;
	int			tmp;
	int			space;

	road2 = *lst_road;
	start = lm_search_s_e(lst_room, 1);
	space = 0;
	while (i != 1)
	{
		tmp = 1;
		while (tmp < i - 1 && road2)
		{
			road2 = road2->next;
			tmp++;
		}
		road1 = road2->next;
		if (ft_strcmp(road1->name, end_room->name) == 0)
		{
			if (road2->name_ant != 0)
			{
				if (space == 0)
					ft_printf("L%d-%s", road2->name_ant, end_room->name);
				else
					ft_printf(" L%d-%s", road2->name_ant, end_room->name);
				space = 1;
				road2->name_ant = 0;
				end_room->ants++;
			}
		}
		else if (ft_strcmp(road2->name, start) == 0 && road2->name_ant >= 1)
		{
			if (road1->name_ant == 0 && road2->name != 0)
			{
				if (space == 0)
					ft_printf("L%d-%s", *nb_ants, road1->name);
				else
					ft_printf(" L%d-%s", *nb_ants, road1->name);
				space = 1;
				road1->name_ant = *nb_ants;
				road2->name_ant--;
				*nb_ants -= 1;
			}
		}
		else if (road1->name_ant == 0 && road2->name_ant != 0)
		{
			if (space == 0)
				ft_printf("L%d-%s", road2->name_ant, road1->name);
			else
				ft_printf(" L%d-%s", road2->name_ant, road1->name);
			space = 1;
			road1->name_ant = road2->name_ant;
			road2->name_ant = 0;
		}
		road2 = *lst_road;
		i--;
	}
	ft_printf("\n");
	free(start);
	return (0);
}

int		lm_display(t_visit **lst_road, t_room **lst_room, int nb_ants)
{
	t_room		*room_end;
	int			i;
	int			tmp;

	tmp = nb_ants;
	i = lm_count_lst(lst_road);
	lm_get_end(lst_room, &(room_end));
	while (room_end->ants != nb_ants)
		lm_move_ants(lst_road, room_end, i, lst_room, &tmp);
	return (1);
}
