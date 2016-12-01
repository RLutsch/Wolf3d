/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deleteindlist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:54:42 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 10:54:43 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_dlist.h>
#include <stdlib.h>

t_index		*ft_deleteindlist(t_index *list, unsigned int position)
{
	t_dlist		*tmp;

	if (position <= 0 || position > list->size)
		return (list);
	if (position == 1)
		return (ft_deletefirstdlist(list));
	if (position == list->size)
		return (ft_deletelastdlist(list));
	tmp = list->first;
	while (--position && tmp)
		tmp = tmp->next;
	if (!position && tmp)
	{
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		free(tmp);
		tmp = NULL;
		list->size--;
	}
	return (list);
}
