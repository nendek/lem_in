/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:35:11 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:41:42 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		*ft_last_two(t_param param)
{
	int		i;
	int		*ret;

	i = 0;
	if (!(ret = malloc(sizeof(int) * param.width)))
		return (NULL);
	param.width--;
	while (i < (int)param.width)
		if (ft_is_in_at(param.flags, '0', 5))
			ret[i++] = '0';
		else
			ret[i++] = ' ';
	ret[i] = 0;
	return (ret);
}

static int		*ft_last_one(t_param param, int *verif)
{
	int		i;
	int		*ret;

	i = 0;
	if (!(ret = malloc(sizeof(int) * param.width + 1)))
		return (NULL);
	ret[i] = verif[0];
	i++;
	while (i < (int)param.width)
		if (ft_is_in_at(param.flags, '0', 5))
			ret[i++] = '0';
		else
			ret[i++] = ' ';
	ret[i] = 0;
	i = 0;
	while (verif[i] != 0)
	{
		verif[i] = verif[i + 1];
		i++;
	}
	verif[i] = 0;
	return (ret);
}

static int		*ft_last(t_param param, int *verif)
{
	if (ft_is_in_at(param.flags, '-', 5))
		return (ft_last_one(param, verif));
	else
		return (ft_last_two(param));
}

static int		ft_select_conv_two(int *str, int *i, t_param *param, int *verif)
{
	char	*itc;

	if (!(itc = ft_itoc(str)))
		return (0);
	if (!(ft_read_param(itc, i, param, verif)))
		return (0);
	free(itc);
	return (1);
}

int				*ft_select_conv(va_list *ap, int *str, int *verif)
{
	int		i;
	int		j;
	t_param	param;
	int		*ret;

	i = 1;
	ret = NULL;
	if (!(ft_select_conv_two(str, &i, &param, verif)))
		return (NULL);
	j = 0;
	while (g_tab_char[j] != '\0')
	{
		if (g_tab_char[j] == str[i])
		{
			if (!(ret = g_tab_ptrf[j](ap, param)))
				return (NULL);
			return (ret);
		}
		j++;
	}
	free(ret);
	if (param.width > 0)
		return (ft_last(param, verif));
	return (NULL);
}
