
#include "lem_in.h"

void	lm_room_free(t_room *room)
{
	t_room *tmp;
	
	if (room)
		while (room)
		{
			tmp = room->next;
			free(room->name);
			free(room);
			room = tmp;
		}
}

void	lm_tunnel_free(t_tunnel *tunnel)
{
	t_tunnel *tmp;
	
	if (tunnel)
		while (tunnel)
		{
			tmp = tunnel->next;
			free(tunnel->name1);
			free(tunnel->name2);
			free(tunnel);
			tunnel = tmp;
		}
}

void	lm_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
