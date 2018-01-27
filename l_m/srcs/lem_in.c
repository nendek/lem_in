/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:31:48 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/27 16:14:39 by pnardozi         ###   ########.fr       */
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

t_tunnel		*lm_search_tunnel(t_tunnel **begin_list, char *name, int nb_sol)
{
	t_tunnel *lst;
	int			i;
	static int	change_sol = 0;
	static int	tmp = 0;

	if (tmp != nb_sol)
	{
		change_sol = 1;
		tmp = nb_sol;
	}
	i = 0;
	lst = *begin_list;
	if (lst)
		while (lst)
		{
			if (change_sol == 0)
			{
				if (ft_strcmp(lst->name2, name) == 0 && lst->visit == 0)
				{
					i = 1;
					break ;
				}
			}
			if (change_sol == 1)
			{
				if (ft_strcmp(lst->name2, name) == 0 && lst->visit == 0)
				{
					change_sol = 2;
					i = 1;
					break ;
				}
			}
			if (change_sol == 2)
			{
				if (lst->visit == 0)
					if (ft_strcmp(lst->name2, name) == 0)
					{
						i = 1;
						break ;
					}
				if (lst->visit != 0 && change_sol == 2)
					if (ft_strcmp(lst->name2, name) == 0)
					{
						i = 1;
						break ;
					}
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
	static int	nb_sol = 0;

	while ((tunnel = lm_search_tunnel(begin_list, end, nb_sol)) != NULL)
	{
		ft_printf("nb sol = %d\n", nb_sol);
		tunnel->visit += 1;
		ft_printf("tunnel = %s-%s\n", tunnel->name1, tunnel->name2);
		if (ft_strcmp(tunnel->name1, start) == 0)
		{
			ft_printf("t as trouver start encule\n");
			nb_sol++;
		}
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
