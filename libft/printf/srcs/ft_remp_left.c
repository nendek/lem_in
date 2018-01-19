/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remp_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:31:43 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:49:13 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_remp_left_two(char *str, t_param param)
{
	if (param.precision >= (int)param.width)
		ft_remp_left_preci(str);
	else if (param.precision < (int)param.width)
		ft_remp_left_preci_two(str, param);
}

void		ft_remp_left(char *str, long long var, int i, t_param param)
{
	char	*ret;
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (!(ret = ft_long_itoa(var)))
		return ;
	if (((ft_is_in_at(param.flags, '+', 5)) && var >= 0))
		str[j++] = '+';
	else if (((ft_is_in_at(param.flags, ' ', 5)) && var >= 0))
		str[j++] = ' ';
	while (ret[k] != '\0')
	{
		str[k + j] = ret[k];
		k++;
	}
	free(ret);
	j = k + j;
	while (j < i)
		str[j++] = ' ';
	str[j] = '\0';
	ft_remp_left_two(str, param);
}

void		ft_remp_left_preci(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	if (!(tmp = ft_strdup(str)))
		return ;
	i = 0;
	j = 0;
	while (tmp[i] != '\0')
		i++;
	i--;
	while (tmp[i] == ' ' && i >= 0)
	{
		str[j++] = '0';
		i--;
	}
	i = 0;
	while (tmp[i] != ' ' && tmp[i] != '\0')
		str[j++] = tmp[i++];
	free(tmp);
}

void		ft_remp_left_preci_two(char *str, t_param param)
{
	int		i;
	char	*tmp;
	int		diff;
	int		j;

	i = 0;
	j = 0;
	if (str[0] == '+' || str[0] == '-')
		j++;
	while (ft_isdigit(str[i + j]) == 1)
		i++;
	if (param.precision <= i)
		return ;
	diff = param.precision - i;
	tmp = ft_strdup(str);
	if (j == 1)
		diff++;
	i = j;
	while (i < diff)
		str[i++] = '0';
	while (ft_isdigit(tmp[j]))
		str[i++] = tmp[j++];
	free(tmp);
}
