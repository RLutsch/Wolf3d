/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:08:38 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 11:08:41 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	int				j;

	if (s == 0)
		return (0);
	str = (char *)malloc((len + 1) * sizeof(*str));
	i = start;
	j = 0;
	if (str == 0)
		return (0);
	while (i < (start + len) && s[i])
		str[j++] = s[i++];
	str[j] = 0;
	return (str);
}
