/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addfirstdlist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:52:04 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 10:52:07 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_dlist.h>
#include <stdlib.h>

t_dlist			*ft_addfirstdlist(t_index *list, char *data)
{
	t_dlist		*node;

	if (list == NULL || data == NULL)
		return (NULL);
	node = (t_dlist *)malloc(sizeof(*node));
	if (node)
	{
		node->name = data;
		node->prev = NULL;
		if (list->last == NULL)
		{
			list->first = node;
			list->last = node;
			node->next = NULL;
		}
		else
		{
			list->first->prev = node;
			node->next = list->first;
			list->first = node;
		}
		list->size++;
	}
	return (node);
}
