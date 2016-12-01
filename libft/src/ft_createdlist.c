/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createdlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:53:50 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 10:53:51 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_dlist.h>
#include <stdlib.h>

t_index			*ft_createdlist(void)
{
	t_index		*tmp;

	tmp = (t_index *)malloc(sizeof(*tmp));
	if (tmp)
	{
		tmp->size = 0;
		tmp->first = NULL;
		tmp->last = NULL;
	}
	return (tmp);
}
