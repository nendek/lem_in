/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:50:31 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/11 19:10:27 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		lm_parse_tunnel(t_room **room, t_tunnel **tunnel,\
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

static int		lm_parse_room(t_room **room, t_index *index, char *line)
{
	if (!(lm_get_room(room, index->start_end, index->ants, line))\
					|| index->sec_part != 0)
	{
		free(line);
		return (0);
	}
	if (index->start_end != 0)
		index->start_end = 0;
	return (1);
}

static int		lm_parse_se2(t_room **room, int *start_end)
{
	if (*start_end != 0)
		return (0);
	*start_end = ROOM_END;
	if (lm_check_e(room))
		return (0);
	return (1);
}

static int		lm_parse_se(char *line, t_room **room, int *start_end)
{
	if (ft_strcmp(line, "##start") == 0)
	{
		if (*start_end != 0)
		{
			free(line);
			return (0);
		}
		*start_end = ROOM_START;
		if (lm_check_s(room))
		{
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

static int		lm_parse2(t_tunnel **tunnel, t_room **room,\
					t_index *index, char *line)
{
	if (line[0] == '#')
	{
		if (!(lm_parse_se(line, room, &index->start_end)))
			return (0);
	}
	else if ((ft_is_in(line, ' ')) == 2)
	{
		if (!(lm_parse_room(room, index, line)))
			return (0);
	}
	else if ((ft_is_in(line, '-')) == 1)
	{
		index->sec_part = 1;
		if (!(lm_parse_tunnel(room, tunnel, index->start_end, line)))
			return (0);
	}
	else
	{
		free(line);
		return (0);
	}
	return (1);
}

int				lm_parse(t_tunnel **tunnel, t_room **room, int *ants)
{
	char		*line;
	t_index		index;

	line = NULL;
	index.sec_part = 0;
	index.start_end = 0;
	if (get_next_line_one_file(0, &line) == -1)
	{
		free(line);
		return (0);
	}
	if (!(lm_get_ants(&index.ants, line)))
		return (0);
	free(line);
	while (get_next_line_one_file(0, &line) > 0)
	{
		ft_printf("%s\n", line);
		if (!(lm_parse2(tunnel, room, &index, line)))
			return (0);
		free(line);
	}
	*ants = index.ants;
	return (1);
}
