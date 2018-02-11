/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:31:48 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/11 21:21:16 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char			*lm_search_s_e(t_room **begin_list, int s_e)
{
	t_room		*lst;
	char		*tmp;

	tmp = NULL;
	lst = *begin_list;
	if (lst)
		while (lst)
		{
			if (lst->start_end == s_e)
				break ;
			lst = lst->next;
		}
	if (lst)
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
		else if (check_tunnel->room1->start_end == 2 && check_tunnel->room2->start_end == 1)
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
	lm_visit_free(&to_visit);
	lm_visit_free(&visited);
	return (0);
}

void	lm_print_se(t_room **begin_list, int nb_ants)
{
	t_room	*lst;
	int		i;

	i = 0;
	lst = *begin_list;
	if (lst->start_end != 2)
		lst = lst->next;
	while (i != nb_ants + 1)
	{
		ft_printf("L%d-%s\n", i, lst->name);
		i++;
	}
}

void	lm_error(t_tunnel **lst_tunnel, t_room **lst_room, t_visit **lst_road)
{
	lm_room_free(lst_room);
	lm_tunnel_free(lst_tunnel);
	lm_visit_free(lst_road);
}

int		main(void)
{
	t_tunnel	*tunnel;
	t_room		*room;
	t_visit		*road;
	int			ants;

	tunnel = NULL;
	room = NULL;
	road = NULL;
	if (!(lm_parse(&tunnel, &room, &ants)))
	{
		ft_printf("Error\n");
		lm_error(&tunnel, &room, &road);
		return (0);
	}
	if (lm_algo(&tunnel, &road, &room) == 1 && road != NULL)
		lm_print_se(&room, ants);
	else if (road != NULL)
		lm_push_ants(ants, &road, &room);
	else
		ft_printf("Error\n");
	lm_error(&tunnel, &room, &road);
	return (0);
}
