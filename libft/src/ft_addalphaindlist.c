/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addalphaindlist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:51:45 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 10:51:47 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_dlist.h>
#include <ft_fc_str.h>

t_dlist			*ft_addalphaindlist(t_index *list, char *data)
{
	int			position;
	t_dlist		*node;

	if (list == NULL || data == NULL)
		return (NULL);
	position = (data[0] < 64 ? 1 : list->size + 1);
	node = (data[0] < 64 ? list->first : list->last);
	if (data[0] < 64)
	{
		while (node && ft_strcmp(node->name, data) < 0)
		{
			position++;
			node = node->next;
		}
	}
	else
	{
		while (node && ft_strcmp(node->name, data) > 0)
		{
			position--;
			node = node->prev;
		}
	}
	return (ft_addindlist(list, data, position));
}
