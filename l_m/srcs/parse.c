/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:50:31 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/23 17:27:27 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//maps vide
//pas de tunnel (check si start et end son connecter)
//trop grande coordonne

static int lm_parse_tunnel(t_room **room, t_tunnel **tunnel, int start_end, char *line)
{
	if (start_end != 0)
	{
		ft_printf("Erreur: room attendu\n");
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

static int lm_parse_room(t_room **room, int *start_end, int ants, char *line)
{
	if (!(lm_get_room(room, *start_end, ants, line)) || sec_part != 0)
	{
		if (sec_part != 0)
			ft_printf("Erreur: room au mauvais endroit\n");
		free(line);
		return (0);
	}
	if (*start_end != 0)
		*start_end = 0;
	return (1);
}

static int lm_parse_se2(t_room **room, int *start_end)
{
	if (*start_end != 0)
	{
		ft_printf("Erreur: room attendu\n");
		return (0);
	}
	*start_end = ROOM_END;
	if (lm_check_e(room))
	{
		ft_printf("Erreur: end deja existant\n");
		return (0);
	}
	return (1);
}

static int lm_parse_se(char *line, t_room **room, int *start_end)
{
	if (ft_strcmp(line, "##start") == 0)
	{
		if (*start_end != 0)
		{
			ft_printf("Erreur: room attendu\n");
			free(line);
			return (0);
		}
		*start_end = ROOM_START;
		if (lm_check_s(room))
		{
			ft_printf("Erreur: start deja existant\n");
			free(line);
			return (0);
		}
	}
	else if (ft_strcmp(line, "##end") == 0)
		if (!(lm_parse_se2(room, start_end)))
		{
			free(line);
			return (0);
		}
	return (1);
}

int	lm_parse(t_tunnel **tunnel, t_room **room)
{
	char		*line;
	t_index		index;

	sec_part = 0;
	get_next_line_multi(0, &line);
	if (!(lm_get_ants(&index->ants, line)))
		return (0);
	while (get_next_line_multi(0, &line) > 0)
	{
		ft_printf("%s\n", line);
		if (line[0] == '#')
		{
			if (!(lm_parse_se(line, room, &start_end)))
				return (0);
		}
		else if ((ft_is_in(line, ' ')) == 2)
		{
			if (!(lm_parse_room(room, &start_end, ants, line)))
				return (0);
		}
		else if ((ft_is_in(line, '-')) == 1)
		{
			sec_part = 1;
			if (!(lm_parse_tunnel(room, tunnel, start_end, line)))
				return (0);
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
