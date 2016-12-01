/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:00:09 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 11:00:12 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*dstcpy;
	const char	*srccpy;

	dstcpy = (char *)dst;
	srccpy = (const char *)src;
	if (dst > src)
	{
		while (n--)
			dstcpy[n] = srccpy[n];
	}
	else
	{
		while (n--)
			*dstcpy++ = *srccpy++;
	}
	return (dst);
}
