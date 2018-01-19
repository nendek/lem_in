/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 14:30:50 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/17 14:30:54 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_is_in_pos(char const *s, int c)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0' && s[i] != (char)c && s[i] != EOF)
			i++;
		return (i);
	}
	return (0);
}
