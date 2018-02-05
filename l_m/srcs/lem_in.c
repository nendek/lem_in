/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:31:48 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/05 18:23:45 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				print_lstvisit(t_visit **begin_list)
{
	t_visit *lst;

	lst = *begin_list;
	while (lst)
	{
		ft_printf("name = %s\n", lst->name);
		lst = lst->next;
	}
}

void				print_grey(t_room **begin_list)
{
	t_room *lst;

	lst =*begin_list;
	while (lst)
	{
		ft_printf("name = %s, grey = %d\n", lst->name, lst->grey);
		lst = lst->next;
	}
}

static char			*lm_search_s_e(t_room **begin_list, int s_e)
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

static void	lm_reset_visit(t_room **begin_list)
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

static int		lm_algo(t_tunnel **lst_tunnel, t_visit **lst_road, t_room **lst_room)
{
	int			ret;
	t_visit		*visited;
	t_visit		*to_visit;
	t_tunnel	*check_tunnel;

	visited = NULL;
	to_visit = NULL;
	check_tunnel = *lst_tunnel;
	while (check_tunnel)
	{
		if (check_tunnel->room1->start_end == 1 && check_tunnel->room2->start_end == 2)
		{
			lm_pushfront_tovisit(lst_road, check_tunnel->name2);
			lm_pushfront_tovisit(lst_road, check_tunnel->name1);
			return (1);
		}
		else if (check_tunnel->room1->start_end == 2 && check_tunnel->room1->start_end == 1)
		{
			lm_pushfront_tovisit(lst_road, check_tunnel->name1);
			lm_pushfront_tovisit(lst_road, check_tunnel->name2);
			return (1);
		}
		check_tunnel = check_tunnel->next;
	}
	ret = lm_bfs(lst_tunnel, &visited, &to_visit, lm_search_s_e(lst_room, 1));
	while (ret == 2)
	{
		lm_visit_free(&to_visit);
		lm_find_road(lst_road, &visited, lst_tunnel, lm_search_s_e(lst_room, 2));
		lm_visit_free(&visited);
		lm_reset_visit(lst_room);
		ret = lm_bfs(lst_tunnel, &visited, &to_visit, lm_search_s_e(lst_room, 1));
	}
	return (0);
}

int		main(void)
{
	t_tunnel	*tunnel;
	t_room		*room;
	t_visit		*road;

	tunnel = NULL;
	room = NULL;
	road = NULL;
	lm_parse(&tunnel, &room);
	lm_algo(&tunnel, &road, &room);

	print_lstvisit(&road);


	lm_room_free(&room);
	lm_tunnel_free(&tunnel);
	return (0);
}
