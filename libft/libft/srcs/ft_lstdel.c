/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:39:22 by pnardozi          #+#    #+#             */
/*   Updated: 2017/11/12 17:37:37 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	if (*alst && del)
		while (*alst)
		{
			(*del)((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = (*alst)->next;
		}
}
