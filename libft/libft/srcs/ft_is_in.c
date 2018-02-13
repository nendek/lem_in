/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:47:38 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/13 18:03:19 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_in(char *line, char c)
{
	int	i;
	int ret;

	i = 0;
	ret = 0;
	if (line)
		while (line[i])
		{
			if (line[i] == c)
				ret++;
			i++;
		}
	return (ret);
}
