
#include "lem_in.h"

int	lm_get_ants(t_room *room, char *line)
{
	long long	nb_ants;
	int		i;

	i = 0;
	get_next_line_multi(0, &line);
	ft_printf("%s\n", line);
	while (line[i])
	{
		if (!(ft_isdigit(line[i])) || i >= 18)
			return (0);
		i++;
	}
	nb_ants = ft_long_atoi(line);
	if (nb_ants > INT_MAX || nb_ants < INT_MIN)
		return (0);
	room->ants = (int)nb_ants;
	free(line);
	return (1);
}

int	lm_get_room2(t_room *room, char *line, int *i)
{
	char		*tmp;
	int		j;
	long long	nb;

	*i += 2;
	j = *i;
	while (line[*i + 1] != ' ' && line[*i] != '\n' && line [*i] != '\0')
	{
		if (!(ft_isdigit(line[*i])) && *i >= 18)
			return (0);
		*i += 1;
	}
	tmp = ft_strndup(line, j, *i);
	nb = ft_long_atoi(tmp);
	if (nb > INT_MAX || nb < INT_MIN)
	{
		free(tmp);
		return (0);
	}
	room->pos.x = nb;
	free(tmp);
	*i += 2;
	j = *i;
	while (line[*i + 1] != '\n' && line [*i + 1] != '\0')
	{
		if (!(ft_isdigit(line[*i])) && *i >= 18)
			return (0);
		*i += 1;
	}
	if (line[*i + 1] != '\n')
		return (0);
	tmp = ft_strndup(line, j, *i);
	nb = ft_long_atoi(tmp);
	if (nb > INT_MAX || nb < INT_MIN)
	{
		free(tmp);
		return (0);
	}
	room->pos.y = nb;
	free(tmp);
	return (1);
}
int	lm_get_room(t_room *room, char *line)
{
	int		i;

	i = 0;
	ft_printf("line = %s\n", line);
	while (line[i + 1] != ' ' && line[i] != '\n' && line [i] != '\0')
		i++;
	if (line[i] == '\n' || line [i] == '\0')
	{
		ft_printf("Erreur name room\n");
		return (0);
	}
	room->name = ft_strndup(line, 0, i);
	ft_printf("room->name = %s\n", room->name);
	if (!(lm_get_room2(room, line, &i)))
	{
		ft_printf("Erreur coordonne room\n");
		return (0);
	}
	return (1);
}

int	lm_parse(t_tunnel *tunnel, t_room *room)
{
	char	*line;
	
	//
	tunnel = NULL;
	//
	line = NULL;
	if (!(lm_get_ants(room, line)))
	{
		ft_printf("Defaut nombres de fourmis.\n");
		free(line);
		return (0);
	}	
	return (1);
}

int	main(void)
{
	t_tunnel	*tunnel;
	t_room		*room;

	room = lm_room_lstnew();
	tunnel = lm_tunnel_lstnew();
	lm_parse(tunnel, room);
	return (0);
}
