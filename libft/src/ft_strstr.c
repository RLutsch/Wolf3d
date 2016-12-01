/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:08:27 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 11:08:29 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str1, const char *str2)
{
	int		i;
	int		ii;
	int		j;

	i = 0;
	ii = 0;
	j = 0;
	if (*str2 == 0)
		return ((char *)str1);
	while (str1[i] != '\0')
	{
		while (str1[ii] == str2[j])
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
