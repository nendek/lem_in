/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_ants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:30:59 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/22 17:31:17 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lm_get_ants(int *ants, char *line)
{
	long long	nb_ants;
	int			i;

	i = 0;
	ft_printf("%s\n", line);
	while (line[i])
	{
		if (!(ft_isdigit(line[i])) || i >= 18)
			return (0);
		i++;
	}
	nb_ants = ft_long_atoi(line);
	if (nb_ants > INT_MAX || nb_ants < INT_MIN)
		return (0);
	*ants = nb_ants;
	return (1);
}
