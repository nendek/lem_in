/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 10:27:13 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/12 10:34:10 by pnardozi         ###   ########.fr       */
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
		new->name_ant = 0;
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
		*begin_list = lm_tovisit_lstnew(name);
	return (0);
}

int		lm_check_name(t_room **begin_list, char *name, t_room **tunnel)
{
	t_room	*lst;
	int		ok;

	ok = 0;
	lst = *begin_list;
	if (lst)
		while (lst)
		{
			if ((ft_strcmp(lst->name, name)) == 0)
			{
				*tunnel = lst;
				ok++;
			}
			lst = lst->next;
		}
	return (ok);
}
