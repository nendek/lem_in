/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ants2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 10:47:10 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/12 10:51:05 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lm_count_road(t_visit **begin_list, char *start)
{
	t_visit	*lst;
	int		i;

	i = 0;
	lst = *begin_list;
	if (lst)
		while (lst)
		{
			if (ft_strcmp(lst->name, start) == 0)
				i++;
			lst = lst->next;
		}
	free(start);
	return (i);
}

void	lm_get_length_road(int *length_road, t_visit **lst_road,\
		t_room **lst_room)
{
	t_visit *lst;
	int		i;
	int		length;
	char	*end;

	i = 0;
	length = 0;
	lst = *lst_road;
	end = lm_search_s_e(lst_room, 2);
	if (lst)
		while (lst)
		{
			length++;
			if (ft_strcmp(lst->name, end) == 0)
			{
				length_road[i] = length;
				i++;
				length = 0;
			}
			lst = lst->next;
		}
	free(end);
}

int		lm_sumlength_road(int *length_road, int nb_road)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	while (i < nb_road)
	{
		sum += length_road[i];
		i++;
	}
	return (sum);
}
