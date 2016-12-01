/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:59:15 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 10:59:19 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_mem.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	if (size == 0)
		return (0);
	ptr = malloc(size);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, size);
	return (ptr);
}
