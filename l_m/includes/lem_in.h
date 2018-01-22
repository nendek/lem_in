/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:50:58 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/22 17:37:27 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "ft_printf.h"

# define ROOM_START 1
# define ROOM_END 2

typedef struct			s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct			s_room
{
	char			*name;
	t_pos			pos;
	int			ants;
	int			start_end;
	struct s_room		*next;
}				t_room;

typedef struct			s_tunnel
{
	char			*name1;
	char			*name2;
	t_room			*room1;
	t_room			*room2;
	int			weight;
	struct s_tunnel		*next;
}				t_tunnel;

void				lm_room_free(t_room *room);
void				lm_tunnel_free(t_tunnel *tunnel);
void				lm_free_tab(char **tab);

t_room				*lm_room_lstnew(void);
t_room				*lm_pushback_room(t_room **begin_list);
t_tunnel			*lm_tunnel_lstnew(void);
t_tunnel			*lm_pushback_tunnel(t_tunnel **begin_list);

int				lm_check_name_double(t_room **begin_list, char *name);
int				lm_check_name(t_room **begin_list, char *name, t_room *tunnel);
int					lm_get_ants(int *ants, char *line);
int					lm_get_room(t_room **begin_list, int s_e, int nb_ants, char *line);
int					lm_parse(t_tunnel **tunnel, t_room **room);
int					lm_check_int(long long nb, char *tmp);

#endif
