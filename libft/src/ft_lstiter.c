/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:58:22 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 10:58:25 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_list.h>

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	while (lst != 0)
	{
		f(lst);
		lst = lst->next;
	}
}
