/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:02:53 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 11:02:55 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_dlist.h>
#include <ft_fc_print.h>

void			ft_readdlist(t_index *list, char direction)
{
	t_dlist		*tmp;

	if (direction == 0)
		tmp = list->first;
	else
		tmp = list->last;
	while (tmp)
	{
		ft_putstr(tmp->name);
		ft_putstr(" > ");
		if (direction == 0)
			tmp = tmp->next;
		else
			tmp = tmp->prev;
	}
	ft_putstr("NULL");
}
