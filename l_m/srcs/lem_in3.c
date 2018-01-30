/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:19:37 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/30 17:32:23 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem_in.h"

char			*lm_search_s_e(t_room **begin_list, int s_e)
{
	t_room		*lst;
	char		*tmp;

	lst = *begin_list;
	if (lst)
		while (lst)
		{
			if (lst->start_end == s_e)
				break ;
			lst = lst->next;
		}
	if (s_e == 1)
	{
		lst->visit = 1;
		lst->visit_check = 1;
	}
	tmp = ft_strdup(lst->name);
	return (tmp);
}

t_room		*lm_search_check(t_tunnel **begin_list, char *name, char **name_old, char *name_old_start)
{
	t_tunnel	*lst;
	static int	i = 0;

	lst = *begin_list;
	if (lst)
		while (lst)
		{
//			ft_printf ("name = %s, name_old = %s, name_old_start = %s, lst->name1 = %s, lst->name2 = %s, lst->room1->visit->check = %d, lst->room2->visit_check = %d\n", name, name_old, name_old_start, lst->name1, lst->name2, lst->room1->visit_check, lst->room2->visit_check);
			if (i == 0)
			{
				if (ft_strcmp(lst->name1, name) == 0 && lst->room2->visit_check == 0 && ft_strcmp(lst->name2, name_old_start) != 0)
				{ 
					*name_old = ft_strdup(name);
					ft_printf("ICICICI 1\n");
					i++;
					return (lst->room2);
				}
				if (ft_strcmp(lst->name2, name) == 0 && lst->room1->visit_check == 0 && ft_strcmp(lst->name1, name_old_start) != 0)
				{
					*name_old = ft_strdup(name);
					ft_printf("ICICICI 2\n");
					i++;
					return (lst->room1);
				}
			}
			else
			{
				if (ft_strcmp(lst->name1, name) == 0 && lst->room2->visit_check == 0)
				{ 
					*name_old = ft_strdup(name);
					return (lst->room2);
				}
				if (ft_strcmp(lst->name2, name) == 0 && lst->room1->visit_check == 0)
				{
					*name_old = ft_strdup(name);
					return (lst->room1);
				}
			}
			lst = lst->next;
		}
	return (NULL);
}

int			lm_algo_check(t_tunnel **begin_list, char *start, char *end, char *name_old_start)
{
	t_room			*room;
	static char		*name_old = NULL;

	while ((room = lm_search_check(begin_list, start, &name_old, name_old_start)) != NULL)
	{
		room->visit_check = 1;
		ft_printf("DANS CHECK : room = %s\n", room->name);
		if (room->start_end == 1)
		{
			ft_printf("ICIC2 !\n");
			return (0);
		}
		if (room->start_end == 2)
		{
			ft_printf("ICIC1 !\n");
			return (1);
		}
		lm_algo_check(begin_list, room->name, end, name_old_start);
	}
	return (-1);
}

t_room		*lm_search_room(t_tunnel **begin_list, char *name, char **name_old, char *end)
{
	t_tunnel	*lst;

	if (ft_strcmp(name, end) == 0)
		return (NULL);
	lst = *begin_list;
	if (lst)
		while (lst)
		{
			ft_printf("return = %d\n", lm_algo_check(begin_list, lst->name2, end, name));
			if (ft_strcmp(lst->name1, name) == 0 && lst->room2->visit == 0 && lm_algo_check(begin_list, lst->name2, end, name) == 1)
			{
				*name_old = ft_strdup(name);
				return (lst->room2);
			}
			if (ft_strcmp(lst->name2, name) == 0 && lst->room1->visit == 0 && lm_algo_check(begin_list, lst->name1, end, name) == 1)
			{
				*name_old = ft_strdup(name);
				return (lst->room1);
			}
			lst = lst->next;
		}
	return (NULL);
}

int		lm_algo(t_tunnel **begin_list, char *start, char *end)
{
	t_room			*room;
	static char		*name_old = NULL;

	while ((room = lm_search_room(begin_list, start, &name_old, end)) != NULL)
	{
		room->visit += 1;
		ft_printf("room = %s\n", room->name);
		if (room->start_end == 2)
		{
			ft_printf("ta trouver solution\n");
			name_old = NULL;
		}
		lm_algo(begin_list, room->name, end);
	}
	return (0);
}

int		main(void)
{
	t_tunnel	*tunnel;
	t_room		*room;
	char		*start;
	char		*end;

	end = NULL;
	start = NULL;
	tunnel = NULL;
	room = NULL;
	lm_parse(&tunnel, &room);
	start = lm_search_s_e(&room, 1);
	end = lm_search_s_e(&room, 2);
	lm_algo(&tunnel, start, end);

	free(start);
	free(end);
	lm_room_free(room);
	lm_tunnel_free(tunnel);
	return (0);
}
