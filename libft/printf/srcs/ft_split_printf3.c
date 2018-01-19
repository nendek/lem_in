/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_printf3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:33:29 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:45:59 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_duplicate(char const *str, char **tab, int *tab_size)
{
	int		i;
	int		j;
	int		k;
	int		size;

	i = 0;
	k = 0;
	while (str[k] != '\0')
	{
		j = 0;
		size = tab_size[i];
		while (j < size && str[k] != '\0')
		{
			tab[i][j] = str[k];
			j++;
			k++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
}

static void	ft_strsplit_printf3(char **tab, int **ret, char *s, int *size_word)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_duplicate(s, tab, size_word);
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			ret[i][j] = tab[i][j];
			j++;
		}
		ret[i][j] = 0;
		i++;
	}
	ret[i] = NULL;
}

static int	ft_strsplit_printf2(char *s, char ***tab, int ***ret,\
		int **size_word)
{
	int nb_word;

	nb_word = ft_count(s);
	if (!(*size_word = malloc(sizeof(int) * (nb_word))))
		return (0);
	ft_countsize(s, *size_word);
	if (!(*tab = malloc(sizeof(char *) * (nb_word + 1))))
		return (0);
	if (!(*ret = malloc(sizeof(int *) * (nb_word + 1))))
		return (0);
	return (nb_word);
}

int			**ft_strsplit_printf(char *s)
{
	int		nb_word;
	int		*size_word;
	char	**tab;
	int		i;
	int		**ret;

	i = 0;
	if (!(nb_word = ft_strsplit_printf2(s, &tab, &ret, &size_word)))
		return (NULL);
	while (i < nb_word)
	{
		if (!(tab[i] = malloc(sizeof(char) * (size_word[i]) + 1)))
			return (NULL);
		if (!(ret[i] = malloc(sizeof(int) * (size_word[i]) + 1)))
			return (NULL);
		i++;
	}
	tab[i] = NULL;
	if (s)
		ft_strsplit_printf3(tab, ret, s, size_word);
	free(size_word);
	while (i >= 0)
		free(tab[i--]);
	free(tab);
	return (ret);
}
