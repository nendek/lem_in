/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:37:46 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/12 10:34:13 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lm_room_free(t_room **begin_list)
{
	t_room *tmp;
	t_room *del;

	del = *begin_list;
	if (del)
		while (del)
		{
			tmp = del->next;
			free(del->name);
			free(del);
			del = tmp;
		}
	*begin_list = NULL;
}

void	lm_visit_free(t_visit **begin_list)
{
	t_visit	*tmp;
	t_visit *del;

	del = *begin_list;
	if (del)
		while (del)
		{
			tmp = del->next;
			free(del->name);
			free(del);
			del = tmp;
		}
	*begin_list = NULL;
}

void	lm_tunnel_free(t_tunnel **begin_list)
{
	t_tunnel *tmp;
	t_tunnel *del;

	del = *begin_list;
	if (del)
		while (del)
		{
			tmp = del->next;
			free(del->name1);
			free(del->name2);
			free(del);
			del = tmp;
		}
	*begin_list = NULL;
}

void	lm_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int		lm_check_name_double(t_room **begin_list, char *name, int p_x, int p_y)
{
	t_room *lst;

	lst = *begin_list;
	if (lst)
		while (lst->next)
		{
			if (lst->pos.x == p_x && lst->pos.y == p_y)
				return (0);
			if ((ft_strcmp(lst->name, name)) == 0)
				return (0);
			lst = lst->next;
		}
	return (1);
}
