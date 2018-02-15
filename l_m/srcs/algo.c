/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 11:23:35 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/15 11:10:06 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		lm_reset_visit(t_room **begin_list)
{
	t_room *lst;

	lst = *begin_list;
	if (lst)
		while (lst)
		{
			lst->visit = 0;
			lst = lst->next;
		}
}

static int		lm_algo2(t_tunnel *check_tunnel, t_visit **lst_road)
{
	while (check_tunnel)
	{
		if (check_tunnel->room1->start_end == 1 &&\
				check_tunnel->room2->start_end == 2)
		{
			lm_pushfront_tovisit(lst_road, check_tunnel->name2);
			lm_pushfront_tovisit(lst_road, check_tunnel->name1);
			return (1);
		}
		else if (check_tunnel->room1->start_end == 2 &&\
				check_tunnel->room2->start_end == 1)
		{
			lm_pushfront_tovisit(lst_road, check_tunnel->name1);
			lm_pushfront_tovisit(lst_road, check_tunnel->name2);
			return (1);
		}
		check_tunnel = check_tunnel->next;
	}
	return (0);
}

int				lm_algo(t_tunnel **lst_tunnel, t_visit **lst_road,\
		t_room **lst_room)
{
	int			ret;
	t_visit		*visited;
	t_visit		*to_visit;
	t_tunnel	*check_tunnel;

	visited = NULL;
	to_visit = NULL;
	check_tunnel = *lst_tunnel;
	if (lm_algo2(check_tunnel, lst_road) == 1)
		return (1);
	ret = lm_bfs(lst_tunnel, &visited, &to_visit, lm_search_s_e(lst_room, 1));
	while (ret == 2)
	{
		lm_visit_free(&to_visit);
		lm_find_road(lst_road, &visited, lst_tunnel,\
				lm_search_s_e(lst_room, 2));
		lm_visit_free(&visited);
		lm_reset_visit(lst_room);
		ret = lm_bfs(lst_tunnel, &visited, &to_visit,\
				lm_search_s_e(lst_room, 1));
	}
	lm_visit_free(&to_visit);
	lm_visit_free(&visited);
	return (0);
}
