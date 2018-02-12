/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 10:30:35 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/12 10:32:55 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lm_parse_tunnel(t_room **room, t_tunnel **tunnel,\
					int start_end, char *line)
{
	if (start_end != 0)
	{
		free(line);
		return (0);
	}
	if ((lm_check_s_e(room)) != 2)
	{
		free(line);
		return (0);
	}
	if (!(lm_get_tunnel(tunnel, room, line)))
	{
		free(line);
		return (0);
	}
	return (1);
}
