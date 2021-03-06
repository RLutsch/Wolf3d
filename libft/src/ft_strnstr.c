/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:07:23 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 11:07:25 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t		i;
	size_t		ii;
	int			j;

	i = 0;
	ii = 0;
	j = 0;
	if (*str2 == 0)
		return ((char *)str1);
	while (str1[i] != '\0' && i < n)
	{
		while (str1[ii] == str2[j] && ii < n)
		{
			j++;
			ii++;
			if (str2[j] == '\0')
				return ((char *)&str1[ii] - j);
		}
		j = 0;
		ii = ++i;
	}
	return (0);
}
