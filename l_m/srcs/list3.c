/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:39:02 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/23 12:39:29 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	lm_check_tunnel_double(t_tunnel **begin_list, char *name1, char *name2)
{
	t_tunnel *lst;

	lst = *begin_list;
	if (lst)
		while (lst->next)
		{
			if ((ft_strcmp(lst->name1, name1)) == 0 && (ft_strcmp(lst->name2, name2)) == 0)
			{
				ft_printf("Erreur : tunnel en double\n");
				return (0);
			}
			lst = lst->next;
		}
	return (1);
}
