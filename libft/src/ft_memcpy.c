/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:59:29 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 11:11:16 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*dstcpy;
	const char		*srccpy;

	dstcpy = (char *)dst;
	srccpy = (const char *)src;
	while (n--)
		*dstcpy++ = *srccpy++;
	return (dst);
}
