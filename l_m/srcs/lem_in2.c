/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:31:48 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/29 17:20:44 by pnardozi         ###   ########.fr       */
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
	if (s_e == 2)
		lst->visit = 1;
	tmp = ft_strdup(lst->name);
	return (tmp);
}

t_room		*lm_search_room(t_tunnel **begin_list, char *name, int nb_sol, char **name_old)
{
	t_tunnel	*lst;
	int		i;
	static int	change_sol = 0;
	static int	tmp = 0;

	//sleep(1);

	if (tmp != nb_sol)
	{
		change_sol = 1;
		tmp = nb_sol;
	}
	i = 0;
	lst = *begin_list;
	//	ft_printf("name_room = %s, name_old = %s\n", name, *name_old);	
	if (lst)
		while (lst)
		{
			if (change_sol != 2)
			{
				if (ft_strcmp(lst->name1, name) == 0 && lst->room2->visit == 0)	
				{
					if (change_sol == 1)
						change_sol = 2;
					*name_old = ft_strdup(name);
					return (lst->room2);
				}
				if (ft_strcmp(lst->name2, name) == 0 && lst->room1->visit == 0)
				{
					if (change_sol == 1)
						change_sol = 2;
 					*name_old = ft_strdup(name);
					return (lst->room1);
				}
			}
			else
			{	
				t_tunnel *lst_tmp;

				lst_tmp = *begin_list;
				while (lst_tmp)
				{
					if (ft_strcmp(lst_tmp->name1, name) == 0 && lst_tmp->room2->visit == 0)	
					{
						if (change_sol == 1)
							change_sol = 2;
						*name_old = ft_strdup(name);
						return (lst_tmp->room2);
					}
					if (ft_strcmp(lst_tmp->name2, name) == 0 && lst_tmp->room1->visit == 0)
					{
						if (change_sol == 1)
							change_sol = 2;
						*name_old = ft_strdup(name);
						return (lst_tmp->room1);
					}
					lst_tmp = lst_tmp->next;
				}
				if (ft_strcmp(lst->name1, name) == 0 && ft_strcmp(lst->name2, *name_old) != 0)
				{
					*name_old = ft_strdup(name);
					return (lst->room2);
				}
				if (ft_strcmp(lst->name2, name) == 0 && ft_strcmp(lst->name1, *name_old) != 0)
				{
					*name_old = ft_strdup(name);
					return (lst->room1);
				}
			}
			lst = lst->next;
		}
	return (NULL);
}

int	lm_algo(t_tunnel **lst_tunnel, t_room **lst_room, char *start, char *end, char *end2)
{
	t_room		*room;
	static int	nb_sol = 0;
	static char *name_old = NULL;

	while ((room = lm_search_room(lst_tunnel, end, nb_sol, &name_old)) != NULL)
	{
		//		ft_printf("nb sol = %d\n", nb_sol);
		room->visit += 1;
		ft_printf("room = %s.\n", room->name);
		if (room->start_end == 1)
		{
			nb_sol++;
			name_old = NULL;
			ft_printf("t as trouver start enculer\n");
			lm_algo(lst_tunnel, lst_room, start, end2, end2);
		}
		else
			lm_algo(lst_tunnel, lst_room, start, room->name, end2);
	}
	return (1);
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
	lm_algo(&tunnel, &room, start, end, end);

	free(start);
	free(end);
	lm_room_free(room);
	lm_tunnel_free(tunnel);
	return (0);
}
