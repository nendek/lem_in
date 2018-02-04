/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:38:17 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/04 15:13:09 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_visit	*lm_tovisit_lstnew(char *name)
{
	t_visit *new;

	if (!(new = malloc(sizeof(t_visit))))
		return (NULL);
	if (new != NULL)
	{
		new->name = ft_strdup(name);
		new->next = NULL;
	}
	return (new);
}

int		lm_pushfront_tovisit(t_visit **begin_list, char *name)
{
	t_visit *lst;

	if (*begin_list)
	{
		lst = lm_tovisit_lstnew(name);
		lst->next = *begin_list;
		*begin_list = lst;
	}
	else
		*begin_list = lm_tovisit_lstnew(name);
	return (0);
}

int		lm_pushback_tovisit(t_visit **begin_list, char *name)
{
	t_visit *lst;

	lst = *begin_list;
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = lm_tovisit_lstnew(name);
	}
	else
		*begin_list =  lm_tovisit_lstnew(name);
	return (0);
}

t_room		*lm_room_lstnew(void)
{
	t_room *new;

	if (!(new = malloc(sizeof(t_room))))
		return (NULL);
	if (new != NULL)
	{
		new->name = NULL;
		new->pos.x = 0;
		new->pos.y = 0;
		new->ants = 0;
		new->start_end = 0;
		new->visit = 0;
		new->grey = 0;
		new->next = NULL;
	}
	return (new);
}

t_room		*lm_pushback_room(t_room **begin_list)
{
	t_room *lst;

	lst = *begin_list;
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = lm_room_lstnew();
		return (lst->next);
	}
	else
		*begin_list = lm_room_lstnew();
	return (*begin_list);
}

t_tunnel	*lm_tunnel_lstnew(void)
{
	t_tunnel *new;

	if (!(new = malloc(sizeof(t_tunnel))))
		return (NULL);
	if (new != NULL)
	{
		new->name1 = NULL;
		new->name2 = NULL;
		new->room1 = NULL;
		new->room2 = NULL;
		new->next = NULL;
	}
	return (new);
}

t_tunnel	*lm_pushback_tunnel(t_tunnel **begin_list)
{
	t_tunnel *lst;

	lst = *begin_list;
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = lm_tunnel_lstnew();
		return (lst->next);
	}
	else
		*begin_list = lm_tunnel_lstnew();
	return (*begin_list);
}
