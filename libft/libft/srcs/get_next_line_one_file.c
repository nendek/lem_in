/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lineV2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 10:00:12 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/11 18:33:55 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line_one_file(const int fd, char **line)
{
	static char	*save;
	char		*tmp;
	char		*buf;
	int			end;
	int			vide;

	end = 1;
	vide = 0;
	while (!(ft_eol(save)) && end != 0)
	{
		buf = ft_strnew(BUFF_SIZE);
		end = read(fd, buf, BUFF_SIZE);
		if (end == 0 && vide == 0)
		{
			ft_strdel(&buf);
			return (-1);
		}
		tmp = ft_strdup(save);
		ft_strdel(&save);
		save = ft_strnew(ft_strlen_p(tmp) + BUFF_SIZE);
		ft_strcpy_p(save, tmp);
		ft_strcat(save, buf);
		ft_strdel(&tmp);
		ft_strdel(&buf);
		vide++;
	}
	*line = ft_strsub(save, 0, ft_is_in_pos(save, '\n'));
	tmp = ft_strsub(save, ft_is_in_pos(save, '\n') + 1, ft_strlen_p(save));
	ft_strdel(&save);
	save = ft_strdup(tmp);
	free(tmp);
	end > 0 ? end = 1 : end;
	return (end);
}
