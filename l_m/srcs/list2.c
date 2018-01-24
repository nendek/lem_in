/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:37:46 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/24 15:19:47 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lm_room_free(t_room *room)
{
	t_room *tmp;

	if (room)
		while (room)
		{
			tmp = room->next;
			free(room->name);
			free(room);
			room = tmp;
		}
}

void	lm_tunnel_free(t_tunnel *tunnel)
{
	t_tunnel *tmp;

	if (tunnel)
		while (tunnel)
		{
			tmp = tunnel->next;
			free(tunnel->name1);
			free(tunnel->name2);
			free(tunnel);
			tunnel = tmp;
		}
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
			{
				ft_printf("Erreur: coordonne en double\n");
				return (0);
			}
			if ((ft_strcmp(lst->name, name)) == 0)
			{
				ft_printf("Erreur nom en double\n");
				return (0);
			}
			lst = lst->next;
		}
	return (1);
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
	if (ok == 0)
		ft_printf("Erreur le nom de room n'existe pas\n'");
	return (ok);
}
