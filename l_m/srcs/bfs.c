/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:07:07 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/05 18:15:18 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			lm_get_children(t_tunnel **lst_tunnel, t_visit **lst_tovisit, char *name)
{
	t_tunnel	*tunnel;
	int			ret;

	ret = 0;
	tunnel = *lst_tunnel;
	if (tunnel)
		while (tunnel)
		{
			if (ft_strcmp(name, tunnel->name1) == 0 && tunnel->room2->visit == 0 && tunnel->room2->grey == 0)
			{
				lm_pushback_tovisit(lst_tovisit, tunnel->name2);
				if (tunnel->room2->start_end == 2)
					return (2);
				ret = 1;
			}
			else if (ft_strcmp(name, tunnel->name2) == 0 && tunnel->room1->visit == 0 && tunnel->room1->grey == 0)
			{
				lm_pushback_tovisit(lst_tovisit, tunnel->name1);
				if (tunnel->room1->start_end == 2)
					return (2);
				ret = 1;
			}
			tunnel = tunnel->next;
		}
	return (ret);
}

static int			lm_visit(t_tunnel **lst_tunnel, t_visit **lst_visited, t_visit **lst_tovisit, char *name)
{
	t_tunnel	*tunnel;

	tunnel = *lst_tunnel;
	if (tunnel)
		while (tunnel)
		{
			if (ft_strcmp(name, tunnel->name1) == 0 && tunnel->room1->grey == 0)
			{
				tunnel->room1->visit = 1;
				lm_pushback_tovisit(lst_visited, name);
				return (lm_get_children(lst_tunnel, lst_tovisit, name));
			}
			if (ft_strcmp(name, tunnel->name2) == 0 && tunnel->room2->grey == 0)
			{
				tunnel->room2->visit = 1;
				lm_pushback_tovisit(lst_visited, name);
				return (lm_get_children(lst_tunnel, lst_tovisit, name));
			}
			tunnel = tunnel->next;
		}
	return (0);
}

static char		*lm_name_tovisit(t_visit **begin_list, int nb)
{
	t_visit		*lst;
	int			i;
	char		*tmp;

	i = 0;
	tmp = NULL;
	lst = *begin_list;
	if (lst)
		while (lst && i != nb)
		{
			lst = lst->next;
			i++;
		}
	if (lst)
		tmp = ft_strdup(lst->name);
	return (tmp);
}

int			lm_bfs(t_tunnel **lst_tunnel, t_visit **lst_visited, t_visit **lst_tovisit, char *start)
{
	char	*name;
	int		i;
	int		ret;

	i = 0;
	ret = lm_visit(lst_tunnel,lst_visited, lst_tovisit, start);
	name = lm_name_tovisit(lst_tovisit, i);
	if (!name)
		return (0);
	while (ret == 1)
	{
		ret = lm_visit(lst_tunnel, lst_visited, lst_tovisit, name);
		i++;
		free(name);
		name = lm_name_tovisit(lst_tovisit, i);
		if (!name)
			return (0);
	}
	
	t_tunnel	*tunnel;
	t_visit		*visit;
	t_visit		*to_visit;
	tunnel = *lst_tunnel;
	visit = *lst_visited;
	to_visit = *lst_tovisit;
	while (visit)
	{
		ft_printf("visiter = %s\n", visit->name);
		visit = visit->next;
	}
	while (to_visit)
	{
		ft_printf("a visiter = %s\n", to_visit->name);
		to_visit = to_visit->next;
	}

	return (ret);
}
