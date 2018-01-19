/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:28:52 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:28:53 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_check_unicode(int c, t_param *param)
{
	if (c >= 0 && c <= 127)
		return ;
	else if (c >= 49792 && c <= 57278)
		(*param).width -= 1;
	else if (c >= 14721152 && c <= 15712191)
		(*param).width -= 2;
	else if (c < -1114111)
		(*param).width -= 3;
}

int				*ft_convert_c(va_list *ap, t_param param)
{
	int		*ret;
	int		c;

	if (param.precision < -2)
		return (NULL);
	if (param.modifier[0] == 'l')
		return (ft_convert_cmaj(ap, param));
	c = (unsigned char)va_arg(*ap, int);
	if (!(ret = ft_flags_c(c, param)))
		return (NULL);
	return (ret);
}

int				*ft_convert_cmaj(va_list *ap, t_param param)
{
	int		*ret;
	int		c;

	if (param.precision < -2)
		return (NULL);
	c = va_arg(*ap, int);
	if (MB_CUR_MAX == 4)
		c = ft_unicode(c);
	ft_check_unicode(c, &param);
	if (!(ret = ft_flags_c(c, param)))
		return (NULL);
	return (ret);
}
