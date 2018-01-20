
#include "lem_in.h"

t_room		*lm_room_lstnew(void)
{
	t_room *new;

	if (!(new = malloc(sizeof(t_room))))
		return (NULL);
	if (new != NULL)
	{
		new->name = NULL;
		new->pos->x = 0;
		new->pos->y = 0;
		new->ants = 0;
		new->start_end = 0;
		new->next = NULL;
	}
	return (new);
}

t_room		*lm_pushback_room(t_room **begin_list)
{
	t_room lst;

	lst = *begin_list;
	if (lst)
	{
		while (lst->next)
			lst = list->next;
		lst->next = lm_room_lstnew();
		return (lst->next)
	}
	else
		*begin_list = lm_room_lstnew();
	return (*begin_list);

}

t_tunnel	*lm_tunnel_lstnew(void)
{
	t_tunnel *new;

	if (!(new = malloc(sizeof(t_tunnel))))
		return (NULL);
	if (new != NULL)
	{
		new->name1 = NULL;
		new->name2 = NULL;
		room1 = NULL;
		room2 = NULL;
		weight = 1;
	}
	return (new);
}


t_tunnel	*lm_pushback_tunnel(t_room **begin_list)
{
	t_room lst;

	lst = *begin_list;
	if (lst)
	{
		while (lst->next)
			lst = list->next;
		lst->next = lm_room_lstnew();
		return (lst->next)
	}
	else
		*begin_list = lm_room_lstnew();
	return (*begin_list);
}
