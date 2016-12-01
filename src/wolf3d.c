/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:59:18 by rlutsch           #+#    #+#             */
/*   Updated: 2016/12/01 11:10:57 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_env	get_env(t_env e)
{
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, W, H, "Wolf3D");
	e.img.img = 0;
	e.view.posx = 12;
	e.view.posy = 5;
	e.view.dirx = -1;
	e.view.diry = 0;
	e.r.planex = 0;
	e.r.planey = 0.80;
	e.time = 0;
	e.oldtime = 0;
	return (e);
}

int		main(int argc, char **argv)
{
	t_env	e;

	ft_putnbr(argc);
	if (argc == 2)
	{
		validate_map(&e, argv[1]);
		e = get_env(e);
		mlx_loop_hook(e.mlx, &lets_get_wolfy, &e);
		mlx_hook(e.win, 2, (1L << 0), &key_press, &e);
		mlx_hook(e.win, 3, (1L << 1), &key_release, &e);
		mlx_hook(e.win, 17, 0L, ft_exit, &e);
		mlx_loop(e.mlx);
	}
	else
	{
		ft_putstr("run the damn thing with a map\n");
	}
	return (0);
}
