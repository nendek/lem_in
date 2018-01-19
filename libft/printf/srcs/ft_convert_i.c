/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:29:33 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:29:35 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			*ft_convert_i(va_list *ap, t_param param)
{
	int		*str;

	str = NULL;
	if (!(str = ft_convert_d(ap, param)))
		return (0);
	return (str);
}
