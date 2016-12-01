/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlastdlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:52:53 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 10:52:54 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_dlist.h>
#include <stdlib.h>

t_dlist			*ft_addlastdlist(t_index *list, char *data)
{
	t_dlist		*node;

	if (list == NULL || data == NULL)
		return (NULL);
	node = (t_dlist *)malloc(sizeof(*node));
	if (node)
	{
		node->name = data;
		node->next = NULL;
		if (list->last == NULL)
		{
			list->first = node;
			list->last = node;
			node->prev = NULL;
		}
		else
		{
			list->last->next = node;
			node->prev = list->last;
			list->last = node;
		}
		list->size++;
	}
	return (node);
}
