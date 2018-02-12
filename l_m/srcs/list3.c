/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:39:02 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/12 10:26:58 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lm_check_tunnel_double(t_tunnel **begin_list, char *name1, char *name2)
{
	t_tunnel *lst;

	lst = *begin_list;
	if (lst)
		while (lst->next)
		{
			if ((ft_strcmp(lst->name1, name1)) == 0 &&\
					(ft_strcmp(lst->name2, name2)) == 0)
				return (0);
			if ((ft_strcmp(lst->name2, name1)) == 0 &&\
					(ft_strcmp(lst->name1, name2)) == 0)
				return (0);
			lst = lst->next;
		}
	return (1);
}

int		lm_check_s(t_room **begin_list)
{
	int		i;
	t_room	*lst;

	lst = *begin_list;
	i = 0;
	if (lst)
		while (lst)
		{
			if (lst->start_end == 1)
				i++;
			lst = lst->next;
		}
	return (i);
}

int		lm_check_e(t_room **begin_list)
{
	int		i;
	t_room	*lst;

	lst = *begin_list;
	i = 0;
	if (lst)
		while (lst)
		{
			if (lst->start_end == 2)
				i++;
			lst = lst->next;
		}
	return (i);
}

int		lm_check_s_e(t_room **begin_list)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (lm_check_s(begin_list))
		i = 1;
	if (lm_check_e(begin_list))
		j = 1;
	return (i + j);
}
