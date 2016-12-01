/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assimilate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:58:52 by rlutsch           #+#    #+#             */
/*   Updated: 2016/12/01 10:58:55 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	get_map_size(t_env *e, int fd)
{
	int		*size;
	char	*line;

	if (get_next_line(fd, &line) < 1)
	{
		ft_putstr("Map Error!");
		exit(0);
	}
	size = ft_strsplittoint(line, ' ');
	e->map.sizex = size[0];
	e->map.sizey = size[1];
}

void	assimilate(t_env *e, int fd)
{
	char	*line;
	int		**worldmap;
	int		i;

	i = 0;
	worldmap = (int **)malloc(sizeof(int *) * e->map.sizex);
	if (worldmap == 0)
	{
		exit(1);
	}
	while (get_next_line(fd, &line) > 0)
	{
		worldmap[i] = ft_strsplittoint(line, ' ');
		i++;
	}
	e->map.map = worldmap;
}

void	validate_map(t_env *e, char *pram)
{
	int		fd;

	if ((fd = open(pram, O_RDONLY)) == -1)
	{
		ft_putstr(pram);
		ft_putstr("\nMap Error!");
		exit(0);
	}
	ft_putstr("Great success!\n");
	get_map_size(e, fd);
	assimilate(e, fd);
	close(fd);
}
