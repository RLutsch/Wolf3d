/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:04:31 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 11:04:34 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_str.h>
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*strcopy;
	int		size;
	int		i;

	i = -1;
	size = ft_strlen(str);
	strcopy = (char *)malloc((size + 1) * sizeof(*strcopy));
	while (++i < size)
		strcopy[i] = str[i];
	strcopy[i] = 0;
	return (strcopy);
}
