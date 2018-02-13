/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 12:54:31 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/13 17:55:02 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lm_equalize_ants(int *n_ants, int nb_ants, int nb_road)
{
	int	i;
	int	diff;

	i = 0;
	diff = 0;
	while (i < nb_road)
	{
		diff += n_ants[i];
		i++;
	}
	diff -= nb_ants;
	i = 0;
	while (diff < 0)
	{
		n_ants[i] += 1;
		i++;
		diff++;
	}
}

void	lm_equalize_ants2(int *n_ants, int nb_road)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < nb_road)
	{
		i = 0;
		while (i < nb_road)
		{
			if (n_ants[i] < 0)
			{
				n_ants[i - 1] = n_ants[i - 1] + n_ants[i];
				n_ants[i] = 0;
				break ;
			}
			i++;
		}
		j++;
	}
}

void	lm_distrib_ants(int nb_ants, int nb_road, int *length_road, int *n_ants)
{
	int		i;
	int		sum;

	i = 0;
	sum = lm_sumlength_road(length_road, nb_road);
	while (i < nb_road)
	{
		n_ants[i] = ((sum - nb_road * length_road[i]) + nb_ants) / nb_road;
		i++;
	}
	lm_equalize_ants(n_ants, nb_ants, nb_road);
	lm_equalize_ants2(n_ants, nb_road);
}

void	lm_affect_ants(int *n_ants, t_room **lst_room, t_visit **lst_road)
{
	char		*start;
	t_visit		*road;
	int			i;

	i = 0;
	road = *lst_road;
	start = lm_search_s_e(lst_room, 1);
	while (road)
	{
		if (ft_strcmp(start, road->name) == 0)
		{
			road->name_ant = n_ants[i];
			i++;
		}
		road = road->next;
	}
	free(start);
}

int		lm_push_ants(int nb_ants, t_visit **lst_road, t_room **lst_room)
{
	int		nb_road;
	int		*length_road;
	int		*n_ants;

	nb_road = lm_count_road(lst_road, lm_search_s_e(lst_room, 1));
	if (!(n_ants = malloc(sizeof(int) * nb_road)))
		return (0);
	if (!(length_road = malloc(sizeof(int) * nb_road)))
		return (0);
	lm_get_length_road(length_road, lst_road, lst_room);
	lm_distrib_ants(nb_ants, nb_road, length_road, n_ants);
	lm_affect_ants(n_ants, lst_room, lst_road);
	lm_display(lst_road, lst_room, nb_ants);
	free(n_ants);
	free(length_road);
	return (1);
}
