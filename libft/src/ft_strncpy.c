/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:06:50 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 11:06:53 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		if (src[i])
			dst[i] = src[i];
		else
		{
			while (i < n)
				dst[i++] = 0;
		}
		i++;
	}
	return (dst);
}
