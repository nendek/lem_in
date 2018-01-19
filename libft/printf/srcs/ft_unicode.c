/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:33:42 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:44:04 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_two(char *str)
{
	int		i;
	char	*ret;
	int		j;

	j = 16;
	i = 0;
	if (!(ret = ft_strdup(g_ret_two)))
		return (0);
	while (str[i] != '\0')
		i++;
	while (j > 9 && i >= 0)
		ret[j--] = str[i--];
	j = 7;
	while (i >= 0)
		ret[j--] = str[i--];
	i = ft_decim(ret);
	free(ret);
	return (i);
}

static int		ft_three(char *str)
{
	int		i;
	char	*ret;
	int		j;

	j = 24;
	i = 0;
	if (!(ret = ft_strdup(g_ret_three)))
		return (0);
	while (str[i] != '\0')
		i++;
	while (j > 17)
		ret[j--] = str[i--];
	j = 15;
	while (j > 9 && i >= 0)
		ret[j--] = str[i--];
	j = 7;
	while (i >= 0)
		ret[j--] = str[i--];
	i = ft_decim(ret);
	free(ret);
	return (i);
}

static int		ft_four(char *str)
{
	int		i;
	char	*ret;
	int		j;

	j = 32;
	i = 0;
	if (!(ret = ft_strdup(g_ret_four)))
		return (0);
	while (str[i] != '\0')
		i++;
	while (j > 25)
		ret[j--] = str[i--];
	j = 23;
	while (j > 17)
		ret[j--] = str[i--];
	j = 15;
	while (j > 9 && i >= 0)
		ret[j--] = str[i--];
	j = 7;
	while (i >= 0)
		ret[j--] = str[i--];
	i = ft_decim(ret);
	free(ret);
	return (i);
}

static char		*ft_bin(int nb)
{
	char	*ret;
	int		i;
	char	base[2];
	int		tmp;

	tmp = nb;
	i = 0;
	base[0] = '0';
	base[1] = '1';
	while (tmp != 0)
	{
		tmp /= 2;
		i++;
	}
	if (!(ret = ft_strnew(i)))
		return (NULL);
	i--;
	while (nb != 0)
	{
		ret[i] = base[nb % 2];
		nb /= 2;
		i--;
	}
	return (ret);
}

int				ft_unicode(int c)
{
	char	*str;
	int		ret;

	ret = 0;
	if (!(str = ft_bin(c)))
		return (0);
	if (c < 0)
		ret = -1;
	else if (c <= 127)
		ret = c;
	else if (c <= 2047)
		ret = ft_two(str);
	else if (c >= 2048 && c <= 55295)
		ret = ft_three(str);
	else if (c >= 57344 && c < 65536)
		ret = ft_three(str);
	else if (c >= 65536 && c <= 1114111)
		ret = ft_four(str);
	else
		ret = -1;
	free(str);
	return (ret);
}
