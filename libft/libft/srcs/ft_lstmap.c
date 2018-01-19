/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:16:18 by pnardozi          #+#    #+#             */
/*   Updated: 2017/11/12 17:43:33 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*current;
	t_list	*new;

	first = NULL;
	if (lst && f)
	{
		while (lst)
		{
			new = (*f)(lst);
			if (first)
			{
				current->next = new;
				current = current->next;
			}
			else
			{
				first = new;
				current = first;
			}
			lst = lst->next;
		}
		return (first);
	}
	return (NULL);
}
