/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:57:30 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 10:57:33 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_list.h>
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;

	if (*alst != 0 && alst != 0 && del != 0)
	{
		tmp = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = 0;
		ft_lstdel(&tmp, del);
	}
}
