/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:31:48 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/21 12:04:15 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		lm_error(t_tunnel **lst_tunnel, \
			t_room **lst_room, t_visit **lst_road)
{
	ft_printf("Error\n");
	lm_room_free(lst_room);
	lm_tunnel_free(lst_tunnel);
	lm_visit_free(lst_road);
}

static void		lm_free(t_tunnel **lst_tunnel, \
			t_room **lst_room, t_visit **lst_road)
{
	lm_room_free(lst_room);
	lm_tunnel_free(lst_tunnel);
	lm_visit_free(lst_road);
}

int				main(void)
{
	t_tunnel	*tunnel;
	t_room		*room;
	t_visit		*road;
	int			ants;
	int			i;

	tunnel = NULL;
	room = NULL;
	road = NULL;
	i = lm_parse(&tunnel, &room, &ants);
	if (i == -1)
	{
		lm_error(&tunnel, &room, &road);
		return (0);
	}
	else if (i == 0)
		ft_printf("Error\n");
	if (lm_algo(&tunnel, &road, &room) == 1 && road != NULL)
		lm_print_se(&room, ants);
	else if (road != NULL)
		lm_push_ants(ants, &road, &room);
	else if (i != 0)
		ft_printf("Error\n");
	lm_free(&tunnel, &room, &road);
	return (0);
}
