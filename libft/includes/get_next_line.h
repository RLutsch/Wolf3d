/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:45:59 by rlutsch           #+#    #+#             */
/*   Updated: 2016/12/01 11:39:23 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 200
# include <unistd.h>

typedef struct	s_gnl
{
	char		*buf;
	int			count;
	int			i;
	int			nl;
	int			fd;
}				t_gnl;
int				get_next_line(int const fd, char **line);
#endif
