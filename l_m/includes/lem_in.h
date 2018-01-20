
#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "ft_printf.h"

# define ROOM_START 1
# define ROOM_END 2

typedef struct		s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct		s_room
{
	char		*name;
	t_pos		pos;
	int		ants;
	int		star_end;
	s_room		*next;
}			t_room;

typedef struct		s_tunnel
{
	char		*name1;
	char		*name2;
	t_room		*room1;
	t_room		*room2;
	int		weight;
}			t_tunnel;

void			lm_room_free(t_room *room);
void			lm_tunnel_free(t_room *tunnel);
void			lm_free_tab(char **tab);
t_room			*lm_room_lstnew(void);
t_room			*lm_pushback_room(t_room **begin_list);
t_tunnel		*lm_tunnel_lstnew(void);
t_tunnel		*lm_pushback_tunnel(t_room **begin_list);

#endif
