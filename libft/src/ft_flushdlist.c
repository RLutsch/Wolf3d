/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flushdlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:55:17 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 10:55:18 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_dlist.h>
#include <stdlib.h>

t_index		*ft_flushdlist(t_index *list)
{
	t_dlist		*tmp;

	if (list == NULL || list->first == NULL)
		return (NULL);
	tmp = list->first;
	while (tmp)
	{
		list->first = tmp->next;
		free(tmp);
		tmp = list->first;
	}
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
	return (list);
}
