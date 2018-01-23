/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:31:48 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/23 16:42:59 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_tunnel	*tunnel;
	t_room		*room;

	tunnel = NULL;
	room = NULL;
	lm_parse(&tunnel, &room);
	lm_room_free(room);
	lm_tunnel_free(tunnel);
	return (0);
}
