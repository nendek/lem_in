/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:32:35 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/16 11:18:50 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lm_check_int(long long nb, char *tmp)
{
	if (nb > INT_MAX || nb < INT_MIN)
	{
		free(tmp);
		return (0);
	}
	return (1);
}

char	*lm_search_s_e(t_room **begin_list, int s_e)
{
	t_room		*lst;
	char		*tmp;

	tmp = NULL;
	lst = *begin_list;
	if (lst)
		while (lst)
		{
			if (lst->start_end == s_e)
				break ;
			lst = lst->next;
		}
	if (lst)
		tmp = ft_strdup(lst->name);
	return (tmp);
}

void	lm_print_se(t_room **begin_list, int nb_ants)
{
	t_room	*lst;
	int		i;

	i = 0;
	lst = *begin_list;
	ft_printf("\n");
	while (lst->start_end != 2)
		lst = lst->next;
	while (i != nb_ants)
	{
		ft_printf("L%d-%s ", i, lst->name);
		i++;
	}
	ft_printf("L%d-%s\n", i, lst->name);
}
