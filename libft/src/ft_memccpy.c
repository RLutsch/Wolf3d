/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:11:22 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 11:11:24 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*dstcpy;
	const char	*srccpy;

	dstcpy = (char *)s1;
	srccpy = (const char *)s2;
	while (n--)
	{
		*dstcpy++ = *srccpy++;
		if (*(srccpy - 1) == (unsigned char)c)
			return ((void *)dstcpy);
	}
	return (0);
}
