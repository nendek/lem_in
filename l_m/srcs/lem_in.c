/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:31:48 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/02 16:46:39 by pnardozi         ###   ########.fr       */
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

int			lm_bfs(t_tunnel **lst_tunnel, t_visit **lst_visited)
{
	t_room		
	//cherche start, on la visite et on met ses fils dans la liste des a visiter
	

	return (0);
}

int		main(void)
{
	t_tunnel	*tunnel;
	t_room		*room;
	char		*start;
	char		*end;
	t_visit		*visited;

	end = NULL;
	start = NULL;
	tunnel = NULL;
	room = NULL;
	lm_parse(&tunnel, &room);
	start = lm_search_s_e(&room, 1);
	end = lm_search_s_e(&room, 2);
	lm_bfs(&tunnel, &visited);

	free(start);
	free(end);
	lm_room_free(room);
	lm_tunnel_free(tunnel);
	return (0);
}
