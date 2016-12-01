/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deletelastdlist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:55:01 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 10:55:02 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_dlist.h>
#include <stdlib.h>

t_index			*ft_deletelastdlist(t_index *list)
{
	t_dlist		*tmp;

	if (list == NULL || list->last == NULL)
		return (NULL);
	tmp = list->last;
	if (list->first != list->last)
	{
		tmp->prev->next = NULL;
		list->last = tmp->prev;
	}
	else
	{
		list->first = NULL;
		list->last = NULL;
	}
	free(tmp);
	tmp = 0;
	list->size--;
	return (list);
}
