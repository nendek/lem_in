/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   road.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:11:31 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/05 18:09:18 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		lm_in_list(t_visit **begin_list, char *room_name)
{
	t_visit	*lst;

	lst = *begin_list;
	if (lst)
		while (lst)
		{
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
	t_tunnel	*tunnel_tmp;
	char		*tmp;

	visited = *lst_visited;
	tunnel = *lst_tunnel;
	lm_pushfront_tovisit(lst_road, end);
	while (visited->next)
		visited = visited->next;
	tmp = ft_strdup(visited->name);
	while (tunnel)
	{
		tunnel_tmp = *lst_tunnel;
		while (tunnel_tmp)
		{
			if (ft_strcmp(tunnel_tmp->name1, tmp) == 0 && tunnel_tmp->room2->grey == 0 && lm_in_list(lst_visited, tunnel_tmp->name2) == 1 && tunnel_tmp->room2->start_end == 1)
			{
				free(tmp);
				lm_pushfront_tovisit(lst_road, tunnel_tmp->name1);
				tunnel_tmp->room1->grey = 1;
				lm_pushfront_tovisit(lst_road, tunnel_tmp->name2);
				return (1);
			}
			else if (ft_strcmp(tunnel_tmp->name2, tmp) == 0 && tunnel_tmp->room1->grey == 0 && lm_in_list(lst_visited, tunnel_tmp->name1) == 1 && tunnel_tmp->room1->start_end == 1)
			{
				free(tmp);
				lm_pushfront_tovisit(lst_road, tunnel_tmp->name2);
				tunnel_tmp->room2->grey = 1;
				lm_pushfront_tovisit(lst_road, tunnel_tmp->name1);
				return (1);
			}
			else
				tunnel_tmp = tunnel_tmp->next;
		}
		if (ft_strcmp(tunnel->name1, tmp) == 0 && tunnel->room2->grey == 0 && lm_in_list(lst_visited, tunnel->name2) == 1)
		{
			free(tmp);
			tmp = ft_strdup(tunnel->name2);
			lm_pushfront_tovisit(lst_road, tunnel->name1);
			tunnel->room1->grey = 1;
			tunnel = *lst_tunnel;
		}
		else if (ft_strcmp(tunnel->name2, tmp) == 0 && tunnel->room1->grey == 0 && lm_in_list(lst_visited, tunnel->name1) == 1)
		{
			free(tmp);
			tmp = ft_strdup(tunnel->name1);
			lm_pushfront_tovisit(lst_road, tunnel->name2);
			tunnel->room2->grey = 1;
			tunnel = *lst_tunnel;
		}
		else
			tunnel = tunnel->next;
	}
	return (0);
}
