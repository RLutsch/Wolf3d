/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:06:22 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 11:06:24 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *str1, const char *str2, size_t n)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (str1[i])
		i++;
	while (str2[j] && j < n)
	{
		str1[i] = str2[j];
		i++;
		j++;
	}
	str1[i] = 0;
	return (str1);
}
