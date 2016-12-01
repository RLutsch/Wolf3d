/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:56:40 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 10:56:43 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void		ft_addnbr(int n, char *str)
{
	if (n != 0)
	{
		if (n / 10 != 0)
			ft_addnbr(n / 10, str - 1);
		n %= 10;
		if (n < 0)
			n = -n;
		*str = n + '0';
	}
	else
		*str = '0';
}

char			*ft_itoa(int n)
{
	char	*str;
	int		ncpy;
	int		size;

	ncpy = n;
	size = 1;
	while (ncpy >= 10 || ncpy <= -10)
	{
		size++;
		ncpy /= 10;
	}
	if (n < 0)
		size++;
	str = (char *)malloc((size + 1) * sizeof(*str));
	if (n < 0)
		str[0] = '-';
	ft_addnbr(n, &str[size - 1]);
	str[size] = 0;
	return (str);
}
