/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:53:26 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 10:53:28 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_tests.h>

int		ft_atoi(const char *str)
{
	int		nb;
	int		isneg;

	isneg = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	nb = 0;
	if (*str == '-')
		isneg = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		nb = nb * 10;
		nb = nb + (*str++ - '0');
	}
	if (isneg == 1)
		nb = -nb;
	return (nb);
}
