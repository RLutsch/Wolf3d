/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:11:05 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 11:11:08 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char		*strcopy;

	strcopy = (const unsigned char *)str;
	while (n--)
	{
		if (*strcopy == (unsigned char)c)
			return ((void *)strcopy);
		strcopy++;
	}
	return (0);
}
