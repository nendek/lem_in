/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:50:31 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/22 16:56:17 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	lm_parse(t_tunnel **tunnel, t_room **room)
{
	char	*line;
	int		ants;
	int		start_end;

	//
	tunnel = NULL;
	//
	get_next_line_multi(0, &line);
	if (!(lm_get_ants(&ants, line)))
	{
		ft_printf("Defaut nombres de fourmis.\n");
		free(line);
		return (0);
	}
	while (get_next_line_multi(0, &line) >= 0)
	{
		ft_printf("%s\n", line);
		if (line[0] == '#')
		{
			if (ft_strcmp(line, "##start") == 0)
				start_end = ROOM_START;
			else if (ft_strcmp(line, "##end") == 0)
				start_end = ROOM_END;
		}
		else if ((ft_is_in(line, ' ')) == 2)
		{
			if (!(lm_get_room(room, start_end, ants, line)))
			{
				free(line);
				return (0);
			}
			if (start_end != 0)
				start_end = 0;
		}
		else
		{
			ft_printf("Erreur format");
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}
