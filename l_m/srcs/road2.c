/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   road2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:06:13 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/13 16:14:44 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lm_in_list(t_visit **begin_list, char *room_name, char *last)
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

int		lm_find_road3(t_tunnel *tunnel, t_visit **lst_road,\
		char **tmp, char *end)
{
	free(*tmp);
	*tmp = ft_strdup(tunnel->name1);
	lm_pushfront_tovisit(lst_road, tunnel->name2);
	tunnel->room2->grey = 1;
	if (tunnel->room1->start_end == 1)
	{
		free(*tmp);
		free(end);
		lm_pushfront_tovisit(lst_road, tunnel->name1);
		return (1);
	}
	return (0);
}

int		lm_find_road2(t_tunnel *tunnel, t_visit **lst_road,\
		char **tmp, char *end)
{
	free(*tmp);
	*tmp = ft_strdup(tunnel->name2);
	lm_pushfront_tovisit(lst_road, tunnel->name1);
	tunnel->room1->grey = 1;
	if (tunnel->room2->start_end == 1)
	{
		free(*tmp);
		free(end);
		lm_pushfront_tovisit(lst_road, tunnel->name2);
		return (1);
	}
	return (0);
}
