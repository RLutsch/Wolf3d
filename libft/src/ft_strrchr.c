/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:07:33 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 11:07:35 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_str.h>

char	*ft_strrchr(const char *str, int c)
{
	int		size;

	size = ft_strlen(str);
	while (size >= 0)
	{
		if (str[size] == (char)c)
			return ((char *)&str[size]);
		size--;
	}
	return (0);
}
