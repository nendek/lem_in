/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   road.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:11:31 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/13 16:57:05 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		lm_find_road4(t_visit **visited, t_tunnel **tunnel,\
		t_visit **lst_visited, t_tunnel **lst_tunnel)
{
	*visited = *lst_visited;
	*tunnel = *lst_tunnel;
}

static void		lm_find_road5(t_visit *visited, char **tmp,\
		t_visit **lst_road, char *end)
{
	while (visited->next)
		visited = visited->next;
	*tmp = ft_strdup(visited->name);
	lm_pushfront_tovisit(lst_road, end);
}

static void		lm_find_road6(char *tmp, char *end)
{
	free(tmp);
	free(end);
}

int				lm_find_road(t_visit **lst_road, t_visit **lst_visited,\
		t_tunnel **lst_tunnel, char *end)
{
	t_visit		*visited;
	t_tunnel	*tunnel;
	char		*tmp;

	lm_find_road4(&visited, &tunnel, lst_visited, lst_tunnel);
	lm_find_road5(visited, &tmp, lst_road, end);
	while (tunnel)
		if (ft_strcmp(tunnel->name1, tmp) == 0 && tunnel->room2->grey == 0\
				&& lm_in_list(lst_visited, tunnel->name2, tunnel->name1) == 1)
		{
			if (lm_find_road2(tunnel, lst_road, &tmp, end) == 1)
				return (1);
			tunnel = *lst_tunnel;
		}
		else if (ft_strcmp(tunnel->name2, tmp) == 0 && tunnel->room1->grey == 0\
				&& lm_in_list(lst_visited, tunnel->name1, tunnel->name2) == 1)
		{
			if (lm_find_road3(tunnel, lst_road, &tmp, end) == 1)
				return (1);
			tunnel = *lst_tunnel;
		}
		else
			tunnel = tunnel->next;
	lm_find_road6(tmp, end);
	return (0);
}
