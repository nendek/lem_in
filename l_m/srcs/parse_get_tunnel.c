/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_tunnel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:39:49 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/11 17:44:01 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		check_name(char *name1, char *name2)
{
	if ((ft_strcmp(name1, name2)) == 0)
		return (0);
	return (1);
}

int				lm_get_tunnel(t_tunnel **tunnel, t_room **room, char *line)
{
	int			i;
	int			j;
	t_tunnel	*lst;

	i = 0;
	lst = lm_pushback_tunnel(tunnel);
	while (line[i + 1] != '-')
		i++;
	if (!(lst->name1 = ft_strndup(line, 0, i)))
		return (0);
	if (!(lm_check_name(room, lst->name1, &(lst->room1))))
		return (0);
	i += 2;
	j = i;
	while (line[i + 1] != '\0')
		i++;
	if (!(lst->name2 = ft_strndup(line, j, i)))
		return (0);
	if (!(lm_check_name(room, lst->name2, &(lst->room2))))
		return (0);
	if (!(check_name(lst->name1, lst->name2)))
		return (0);
	if (!(lm_check_tunnel_double(tunnel, lst->name1, lst->name2)))
		return (0);
	return (1);
}
