/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:49:05 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/07 14:35:11 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		lm_get_pos2(char *line, int *i, int *j, char *tmp)
{
	*i += 2;
	*j = *i;
	while (line[*i] != ' ' && line[*i] != '\0')
	{
		if (!(ft_isdigit(line[*i])) || (*i - *j) >= 18)
		{
			if (tmp)
				free(tmp);
			ft_printf("Erreur coordonne de room\n");
			return (0);
		}
		*i += 1;
	}
	*i -= 1;
	return (1);
}

static void		lm_get_room_se(t_room *room, int nb_ants, int s_e)
{
	if (s_e == 1)
	{
		room->start_end = s_e;
		room->ants = nb_ants;
	}
	else if (s_e == 2)
		room->start_end = s_e;
}

static int		lm_get_pos(t_room *room, char *line, int *i, int *j)
{
	char		*tmp;
	long long	nb;

	tmp = NULL;
	if (!(lm_get_pos2(line, i, j, tmp)))
		return (0);
	if (!(tmp = ft_strndup(line, *j, *i)))
		return (0);
	nb = ft_long_atoi(tmp);
	if (!(lm_check_int(nb, tmp)))
		return (0);
	room->pos.x = nb;
	if (!(lm_get_pos2(line, i, j, tmp)))
		return (0);
	free(tmp);
	if (!(tmp = ft_strndup(line, *j, *i)))
		return (0);
	nb = ft_long_atoi(tmp);
	if (!(lm_check_int(nb, tmp)))
		return (0);
	room->pos.y = nb;
	free(tmp);
	return (1);
}

int				lm_get_room(t_room **begin_list, int s_e, int nb_ants,\
					char *line)
{
	int			i;
	int			j;
	t_room		*room;

	i = 0;
	room = lm_pushback_room(begin_list);
	lm_get_room_se(room, nb_ants, s_e);
	while (line[i + 1] != ' ')
		i++;
	if (!(room->name = ft_strndup(line, 0, i)))
		return (0);
	if (!(lm_get_pos(room, line, &i, &j)))
		return (0);
	if (!(lm_check_name_double(begin_list, room->name,\
					room->pos.x, room->pos.y)))
		return (0);
	//ft_printf("name = %s, start_end = %d, ants = %d, pos.x = %d, pos.y = %d\n", room->name, room->start_end, room->ants, room->pos.x, room->pos.y);
	return (1);
}
