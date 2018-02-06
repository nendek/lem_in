/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   road.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:11:31 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/06 17:43:22 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		lm_in_list(t_visit **begin_list, char *room_name, char *last)
{
	t_visit	*lst;

	lst = *begin_list;
	if (lst)
		while (lst)
		{
			if (ft_strcmp(lst->name, last) == 0)
				return (0);
			if (ft_strcmp(lst->name, room_name) == 0)
				return (1);
			lst = lst->next;
		}
	return (0);
}

int		lm_find_road(t_visit **lst_road, t_visit **lst_visited, t_tunnel **lst_tunnel, char *end)
{
	t_visit		*visited;
	t_tunnel	*tunnel;
	char		*tmp;

	visited = *lst_visited;
	tunnel = *lst_tunnel;
	lm_pushfront_tovisit(lst_road, end);
	while (visited->next)
		visited = visited->next;
	tmp = ft_strdup(visited->name);
	while (tunnel)
	{
		if (ft_strcmp(tunnel->name1, tmp) == 0 && tunnel->room2->grey == 0 && lm_in_list(lst_visited, tunnel->name2, tunnel->name1) == 1)
		{
			free(tmp);
			tmp = ft_strdup(tunnel->name2);
			lm_pushfront_tovisit(lst_road, tunnel->name1);
			tunnel->room1->grey = 1;
			if (tunnel->room2->start_end == 1)
			{
				lm_pushfront_tovisit(lst_road, tunnel->name2);
				return (1);
			}
			tunnel = *lst_tunnel;
		}
		else if (ft_strcmp(tunnel->name2, tmp) == 0 && tunnel->room1->grey == 0 && lm_in_list(lst_visited, tunnel->name1, tunnel->name2) == 1)
		{
			free(tmp);
			tmp = ft_strdup(tunnel->name1);
			lm_pushfront_tovisit(lst_road, tunnel->name2);
			tunnel->room2->grey = 1;
			if (tunnel->room1->start_end == 1)
			{
				lm_pushfront_tovisit(lst_road, tunnel->name1);
				return (1);
			}
			tunnel = *lst_tunnel;
		}
		else
			tunnel = tunnel->next;
	}
	return (0);
}
