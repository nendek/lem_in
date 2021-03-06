/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:50:58 by pnardozi          #+#    #+#             */
/*   Updated: 2018/02/13 18:02:02 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "ft_printf.h"

# define ROOM_START 1
# define ROOM_END 2

typedef struct			s_index
{
	int					ants;
	int					start_end;
	int					sec_part;
}						t_index;

typedef struct			s_pos
{
	int					x;
	int					y;
}						t_pos;

typedef struct			s_room
{
	char				*name;
	t_pos				pos;
	int					ants;
	int					start_end;
	int					visit;
	int					grey;
	struct s_room		*next;
}						t_room;

typedef struct			s_visit
{
	char				*name;
	int					name_ant;
	struct s_visit		*next;
}						t_visit;

typedef struct			s_tunnel
{
	char				*name1;
	char				*name2;
	t_room				*room1;
	t_room				*room2;
	struct s_tunnel		*next;
}						t_tunnel;

int						lm_parse_tunnel(t_room **room,\
		t_tunnel **tunnel, int start_end, char *line);
void					lm_room_free(t_room **begin_list);
void					lm_tunnel_free(t_tunnel **begin_list);
void					lm_free_tab(char **tab);
void					lm_visit_free(t_visit **begin_list);
void					lm_remove_endtunnel(t_tunnel **begin_list);
t_visit					*lm_tovisit_lstnew(char *name);
int						lm_pushback_tovisit(t_visit **begin_list, char *name);
int						lm_pushfront_tovisit(t_visit **begin_list, char *name);
t_room					*lm_room_lstnew(void);
t_room					*lm_pushback_room(t_room **begin_list);
t_tunnel				*lm_tunnel_lstnew(void);
t_tunnel				*lm_pushback_tunnel(t_tunnel **begin_list);
int						lm_find_road(t_visit **lst_road,\
		t_visit **lst_visited, t_tunnel **lst_tunnel, char *end);
int						lm_bfs(t_tunnel **lst_tunnel,\
		t_visit **lst_visited, t_visit **lst_tovisit, char *start);
int						lm_push_ants(int nb_ants,\
		t_visit **lst_road, t_room **lst_room);
char					*lm_search_s_e(t_room **begin_list, int s_e);
int						lm_display(t_visit **lst_road,\
		t_room **lst_room, int nb_ants);
int						lm_check_name_double(t_room **begin_list,\
		char *name, int p_x, int p_y);
int						lm_check_name(t_room **begin_list,\
		char *name, t_room **tunnel);
int						lm_get_ants(int *ants, char *line);
int						lm_get_room(t_room **begin_list,\
		int s_e, int nb_ants, char *line);
int						lm_parse(t_tunnel **tunnel,\
		t_room **room, int *ants);
int						lm_check_int(long long nb, char *tmp);
int						lm_check_tunnel_double(t_tunnel **begin_list,\
		char *name1, char *name2);
int						lm_get_tunnel(t_tunnel **tunnel,\
		t_room **room, char *line);
int						lm_check_s(t_room **begin_list);
int						lm_check_e(t_room **begin_list);
int						lm_check_s_e(t_room **begin_list);
int						lm_algo(t_tunnel **lst_tunnel, \
		t_visit **lst_road, t_room **lst_room);
int						lm_count_road(t_visit **begin_list, char *start);
void					lm_get_length_road(int *length_road, \
		t_visit **lst_road, t_room **lst_room);
int						lm_sumlength_road(int *length_road, int nb_road);
void					lm_print_se(t_room **begin_list, int nb_ants);
int						lm_find_road2(t_tunnel *tunnel, t_visit **lst_road,\
						char **tmp, char *end);
int						lm_find_road3(t_tunnel *tunnel, t_visit **lst_road,\
						char **tmp, char *end);
int						lm_in_list(t_visit **begin_list, \
		char *room_name, char *last);
void					lm_move_ants2(t_pos *index, t_visit **road1,\
		t_visit **road2, int *tmp);
void					lm_move_ants3(int *space, t_room **end_room,\
		t_visit **road2);
void					lm_move_ants4(int *space, t_visit **road1,\
		t_visit **road2, t_pos *index);
void					lm_move_ants5(int *space, t_visit **road1,\
		t_visit **road2);

#endif
