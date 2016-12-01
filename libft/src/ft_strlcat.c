/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:05:33 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 11:05:35 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;

	i = 0;
	while (dst[i] && i < size)
		i++;
	if (i < size - 1)
	{
		while (i < size - 1 && *src)
		{
			dst[i] = *src++;
			i++;
		}
		dst[i] = 0;
	}
	while (*src)
	{
		src++;
		i++;
	}
	return (i);
}
