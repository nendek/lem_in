/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:31:48 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/26 16:15:08 by pnardozi         ###   ########.fr       */
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

int				lm_coutn_link(t_tunnel **begin_list, char *name)
{
	int			i;
	t_tunnel	*lst;

	lst = *begin_list;
	i = 0;
	if (lst)
		while (lst)
		{
			if (ft_strcmp(lst->name1, name) == 0)
				i++;
			lst = lst->next;
		}
	return (i);
}

t_tunnel		*lm_search_tunnel(t_tunnel **begin_list, char *name)
{
	t_tunnel *lst;
	int			i;
	int			links;

	links = lm_coutn_link(begin_list, name);
	ft_printf("name = %s, link = %d\n", name, links);
	i = 0;
	lst = *begin_list;
	if (lst)
		while (lst)
		{
			if (ft_strcmp(lst->name2, name) == 0 && lst->visit <= links)
			{
				i = 1;
				break ;
			}
			lst = lst->next;
		}
	if (i == 1)
		return (lst);
	return (NULL);
}

int				lm_algo(t_tunnel **begin_list, char *start, char *end)
{
	t_tunnel	*tunnel;

	while ((tunnel = lm_search_tunnel(begin_list, end)) != NULL)
	{
		tunnel->visit += 1;
		ft_printf("tunnel = %s-%s\n", tunnel->name1, tunnel->name2);
		if (ft_strcmp(tunnel->name1, start) == 0)
			ft_printf("t as trouver start encule\n");
		lm_algo(begin_list, start, tunnel->name1);
	}
	return (0);
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
	lm_algo(&tunnel, start, end);

	free(start);
	free(end);
	lm_room_free(room);
	lm_tunnel_free(tunnel);
	return (0);
}
