/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 11:42:52 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 11:42:54 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(unsigned long int n)
{
	int		i;

	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_pos(char *str, int i, unsigned long int n)
{
	str[i] = '\0';
	i--;
	while (n != 0)
	{
		str[i] = (n % 10) + '0';
		i--;
		n = n / 10;
	}
}

char		*ft_unsigned_itoa(unsigned long int n)
{
	char	*str;
	int		i;

	i = count(n);
	if (n == 0)
	{
		if (!(str = malloc(sizeof(char) * 2)))
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_pos(str, i, n);
	return (str);
}
