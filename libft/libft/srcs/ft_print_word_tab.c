/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_word_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:42:26 by pnardozi          #+#    #+#             */
/*   Updated: 2017/11/14 15:38:19 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_word_tab(char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
		j = 0;
	}
}
