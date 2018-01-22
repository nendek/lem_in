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

int	lm_get_tunnel(t_tunnel **tunnel, t_room **room, char *line)
{
	int		i;
	int		j;
	t_tunnel	*lst;

	i = 0;
	lst = lm_pushback_tunnel(tunnel);
	while (line[i + 1] != '-')
		i++;
	lst->name1 = ft_strndup(line, 0, i);
	if (!(lm_check_name(room, lst->name1, lst->room1)))
		return (0);
	i += 2;
	j = i;
	while (line[i + 1] != '\0')
		i++;
	lst->name2 = ft_strndup(line, j, i);
	if (!(lm_check_name(room, lst->name2, lst->room2)))
		return (0);
	if ((ft_strcmp(lst->name1, lst->name2)) == 0)
	{
		ft_printf("Erreur : nom identique");
		return (0);
	}
	return (1);
}

int	lm_parse(t_tunnel **tunnel, t_room **room)
{
	char		*line;
	int		ants;
	int		start_end;
	int		sec_part;
	
	sec_part = 0;
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
			if (!(lm_get_room(room, start_end, ants, line)) || sec_part != 0)
			{
				if (sec_part != 0)
					ft_printf("Room au mauvais endroit\n");
				free(line);
				return (0);
			}
			if (start_end != 0)
				start_end = 0;
		}
		else if ((ft_is_in(line, '-')) == 1)
		{
			sec_part = 1;
			if (!lm_get_tunnel(tunnel, room, line))
			{
				free(line);
				return (0);
			}
		}
		else
		{
			ft_printf("Erreur format\n");
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}
