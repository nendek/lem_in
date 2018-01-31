/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:19:37 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/31 14:56:43 by pnardozi         ###   ########.fr       */
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

void		lm_reset_check(t_tunnel **begin_list)
{
	t_tunnel	*lst;

	lst = *begin_list;
	if (lst)
		while (lst)
		{
			lst->room1->visit_check = 0;
			lst->room2->visit_check = 0;
			lst = lst->next;
		}
}

t_room		*lm_search_check(t_tunnel **begin_list, char *name, char **name_old, char *name_old_start)
{
	t_tunnel	*lst;
	static int	i = 0;

	lst = *begin_list;
	if (lst)
		while (lst)
		{
			//	ft_printf ("name = %s, name_old = %s, name_old_start = %s, lst->name1 = %s, lst->name2 = %s, lst->room1->visit->check = %d, lst->room2->visit_check = %d\n", name, *name_old, name_old_start, lst->name1, lst->name2, lst->room1->visit_check, lst->room2->visit_check);
			if (i == 0)
			{
				if (ft_strcmp(lst->name1, name) == 0 && lst->room2->visit_check == 0 && ft_strcmp(lst->name2, name_old_start) != 0)
				{ 
					*name_old = ft_strdup(name);
				ft_printf("name_old_start = %s\n", name_old_start);
		//			ft_printf("ICICICI 1\n");
					i++;
					return (lst->room2);
				}
				if (ft_strcmp(lst->name2, name) == 0 && lst->room1->visit_check == 0 && ft_strcmp(lst->name1, name_old_start) != 0)
				{
					*name_old = ft_strdup(name);

					ft_printf("name_old_start = %s\n", name_old_start);
		//			ft_printf("ICICICI 2\n");
					i++;
					return (lst->room1);
				}
			}
			else
			{
				if (ft_strcmp(lst->name1, name) == 0 && lst->room2->visit_check == 0 && ft_strcmp(lst->name2, *name_old) != 0 && ft_strcmp(lst->name2, name_old_start) != 0)
				{ 
					ft_printf("name_old_start = %s\n", name_old_start);
					*name_old = ft_strdup(name);
		//			ft_printf("ICICICI 3\n");
					return (lst->room2);
				}
				if (ft_strcmp(lst->name2, name) == 0 && lst->room1->visit_check == 0 && ft_strcmp(lst->name1, *name_old) != 0 && ft_strcmp(lst->name1, name_old_start) != 0)
				{
					ft_printf("name_old_start = %s\n", name_old_start);
					*name_old = ft_strdup(name);
		//			ft_printf("ICICICI 4\n");
					return (lst->room1);
				}
			}
			lst = lst->next;
		}
	return (NULL);
}

int			lm_algo_check(t_tunnel **begin_list, char *start, char *end, char *name_old_start, int *i)
{
	t_room			*room;
	static char		*name_old = NULL;

	while ((room = lm_search_check(begin_list, start, &name_old, name_old_start)) != NULL && *i != 1)
	{
		if (ft_strcmp(room->name, end) != 0)
			room->visit_check = 1;
		ft_printf("name = %s, DANS CHECK : room = %s\n", start, room->name);
		if (room->start_end == 1)
		{
		//	ft_printf("ICIC2 !\n");
			return (0);
		}
		if (room->start_end == 2)
		{
			*i = 1;
		//	ft_printf("ICIC1 !\n");
			return (0);
		}
		lm_algo_check(begin_list, room->name, end, name_old_start, i);
	}
	return (0);
}

t_room		*lm_search_room(t_tunnel **begin_list, char *name, char **name_old, char *end)
{
	t_tunnel	*lst;
	int			i;

	i = 0;
	if (ft_strcmp(name, end) == 0)
		return (NULL);
	lst = *begin_list;
	if (lst)
		while (lst)
		{	

			if (ft_strcmp(lst->name1, name) == 0 && lst->room2->visit == 0)
			{
				lm_reset_check(begin_list);
				if (ft_strcmp(lst->name2, end) != 0)
						lm_algo_check(begin_list, lst->name2, end, name, &i);
				else
					i = 1;
				ft_printf("return1 = %d\n", i);
				if (i == 1)
				{
					i = 0;
					*name_old = ft_strdup(name);
					return (lst->room2);
				}
			}
			if (ft_strcmp(lst->name2, name) == 0 && lst->room1->visit == 0)
			{
				lm_reset_check(begin_list);
				if (ft_strcmp(lst->name1, end) != 0) 
					lm_algo_check(begin_list, lst->name1, end, name, &i);
				else
					i = 1;
				ft_printf("return2 = %d\n", i);
				if (i == 1)
				{	
					i = 0;
					*name_old = ft_strdup(name);
					return (lst->room1);
				}
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
			room->visit = 0;
			ft_printf("ta trouver solution\n");
			name_old = NULL;
			return (0);
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
