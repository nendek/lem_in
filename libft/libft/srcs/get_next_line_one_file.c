/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lineV2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 10:00:12 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/17 14:59:36 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line_one_file(const int fd, char **line)
{
	static char	*save;
	char		*tmp;
	char		*buf;
	int			end;

	end = 1;
	while (!(ft_eol(save)) && end != 0)
	{
		buf = ft_strnew(BUFF_SIZE);
		end = read(fd, buf, BUFF_SIZE);
		tmp = ft_strdup(save);
		ft_strdel(&save);
		save = ft_strnew(ft_strlen_p(tmp) + BUFF_SIZE);
		ft_strcpy_p(save, tmp);
		ft_strcat(save, buf);
		ft_strdel(&tmp);
		ft_strdel(&buf);
	}
	*line = ft_strsub(save, 0, ft_is_in_pos(save, '\n'));
	tmp = ft_strsub(save, ft_is_in_pos(save, '\n') + 1, ft_strlen_p(save));
	ft_strdel(&save);
	save = ft_strdup(tmp);
	ft_strdel(&tmp);
	end > 0 ? end = 1 : end;
	return (end);
}
