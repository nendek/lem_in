/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:31:48 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/04 18:17:27 by pnardozi         ###   ########.fr       */
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
	tmp = ft_strdup(lst->name);
	return (tmp);
}

int			lm_get_children(t_tunnel **lst_tunnel, t_visit **lst_tovisit, char *name)
{
	t_tunnel	*tunnel;
	int			ret;

	ret = 0;
	tunnel = *lst_tunnel;
	while (tunnel)
	{
		if (ft_strcmp(name, tunnel->name1) == 0 && tunnel->room2->visit == 0 && tunnel->room2->grey == 0)
		{
			lm_pushback_tovisit(lst_tovisit, tunnel->name2);
			if (tunnel->room2->start_end == 2)
				return (0);
			ret = 1;
		}
		else if (ft_strcmp(name, tunnel->name2) == 0 && tunnel->room1->visit == 0 && tunnel->room1->grey == 0)
		{
			lm_pushback_tovisit(lst_tovisit, tunnel->name1);
			if (tunnel->room1->start_end == 2)
				return (0);
			ret = 1;
		}
		tunnel = tunnel->next;
	}
	return (ret);
}

char		*lm_name_tovisit(t_visit **begin_list, int nb)
{
	t_visit		*lst;
	int			i;
	char		*tmp;

	i = 0;
	tmp = NULL;
	lst = *begin_list;
	while (lst && i != nb)
	{
		lst = lst->next;
		i++;
	}
	if (lst)
		tmp = ft_strdup(lst->name);
	return (tmp);
}

int			lm_visit(t_tunnel **lst_tunnel, t_visit **lst_visited, t_visit **lst_tovisit, char *name)
{
	t_tunnel	*tunnel;

	tunnel = *lst_tunnel;
	while (tunnel)
	{	
		if (ft_strcmp(name, tunnel->name1) == 0)
		{
			tunnel->room1->visit = 1;
			lm_pushback_tovisit(lst_visited, name);
			return (lm_get_children(lst_tunnel, lst_tovisit, name));
		}
		if (ft_strcmp(name, tunnel->name2) == 0)
		{
			tunnel->room2->visit = 1;
			lm_pushback_tovisit(lst_visited, name);
			return (lm_get_children(lst_tunnel, lst_tovisit, name));
		}
		tunnel = tunnel->next;
	}
	return (0);
}

int			lm_bfs(t_tunnel **lst_tunnel, t_visit **lst_visited, t_visit **lst_tovisit, char *start)
{
	char	*name;
	int		i;

	i = 0;
	//cherche start, on la visite et on met ses fils dans la liste des a visiter
	lm_visit(lst_tunnel,lst_visited, lst_tovisit, start);
	name = lm_name_tovisit(lst_tovisit, i);
	while (lm_visit(lst_tunnel, lst_visited, lst_tovisit, name))
	{
		i++;
		name = lm_name_tovisit(lst_tovisit, i);
	}

	
	//
	t_tunnel	*tunnel;
	t_visit		*visit;
	t_visit		*to_visit;
	tunnel = *lst_tunnel;
	visit = *lst_visited;
	to_visit = *lst_tovisit;
	while (visit)
	{
		ft_printf("visiter = %s\n", visit->name);
		visit = visit->next;
	}
	while (to_visit)
	{
		ft_printf("a visiter = %s\n", to_visit->name);
		to_visit = to_visit->next;
	}
	return (0);
}

int		lm_find_road(t_visit **lst_road, t_visit **lst_visited, t_tunnel **lst_tunnel, char *end)
{


int		main(void)
{
	t_tunnel	*tunnel;
	t_room		*room;
	char		*start;
	char		*end;
	t_visit		*visited;
	t_visit		*to_visit;
	t_visit		*road;

	end = NULL;
	start = NULL;
	tunnel = NULL;
	room = NULL;
	lm_parse(&tunnel, &room);
	start = lm_search_s_e(&room, 1);
	end = lm_search_s_e(&room, 2);
	lm_bfs(&tunnel, &visited, &to_visit, start);
	lm_find_road(


	free(start);
	free(end);
	lm_room_free(room);
	lm_tunnel_free(tunnel);
	return (0);
}
