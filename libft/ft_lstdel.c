/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 21:56:12 by tbui              #+#    #+#             */
/*   Updated: 2015/11/25 21:56:56 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list **list;
	t_list *tmp;

	list = alst;
	while (*list)
	{
		tmp = (*list)->next;
		del((*list)->content, (*list)->content_size);
		free(*list);
		*list = tmp;
	}
}
