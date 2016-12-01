/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:59:37 by rlutsch           #+#    #+#             */
/*   Updated: 2016/12/01 10:59:40 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			key_press(int keycode, t_env *e)
{
	if (keycode == 123 || keycode == 86)
		e->view.keys.left = 1;
	if (keycode == 126 || keycode == 91)
		e->view.keys.up = 1;
	if (keycode == 124 || keycode == 88)
		e->view.keys.right = 1;
	if (keycode == 125 || keycode == 84)
		e->view.keys.down = 1;
	return (0);
}

int			key_release(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123 || keycode == 86)
		e->view.keys.left = 0;
	if (keycode == 126 || keycode == 91)
		e->view.keys.up = 0;
	if (keycode == 124 || keycode == 88)
		e->view.keys.right = 0;
	if (keycode == 125 || keycode == 84)
		e->view.keys.down = 0;
	return (0);
}

void		rotate(t_env *e, char dir)
{
	double	tmpdir;
	double	oldplane;
	int		coef;

	coef = 1;
	tmpdir = e->view.dirx;
	oldplane = e->r.planex;
	if (dir == 'R')
		coef = -1;
	e->view.dirx = e->view.dirx * cos(coef * e->view.rotation_spd)
		- e->view.diry * sin(coef * e->view.rotation_spd);
	e->view.diry = tmpdir * sin(coef * e->view.rotation_spd)
		+ e->view.diry * cos(coef * e->view.rotation_spd);
	e->r.planex = e->r.planex * cos(coef * e->view.rotation_spd)
		- e->r.planey * sin(coef * e->view.rotation_spd);
	e->r.planey = oldplane * sin(coef * e->view.rotation_spd)
		+ e->r.planey * cos(coef * e->view.rotation_spd);
}

void		move(t_env *e)
{
	if (e->view.keys.up)
	{
		if (!(e->map.map[(int)(e->view.posx + e->view.dirx
			* e->view.move_spd)][(int)(e->view.posy)]))
			e->view.posx += e->view.dirx * e->view.move_spd;
		if (!(e->map.map[(int)(e->view.posx)][(int)(e->view.posy
			+ e->view.diry * e->view.move_spd)]))
			e->view.posy += e->view.diry * e->view.move_spd;
	}
	if (e->view.keys.left)
		rotate(e, 'L');
	if (e->view.keys.right)
		rotate(e, 'R');
	if (e->view.keys.down)
	{
		if (!(e->map.map[(int)(e->view.posx - e->view.dirx
			* e->view.move_spd)][(int)(e->view.posy)]))
			e->view.posx -= e->view.dirx * e->view.move_spd;
		if (!(e->map.map[(int)(e->view.posx)][(int)(e->view.posy
			- e->view.diry * e->view.move_spd)]))
			e->view.posy -= e->view.diry * e->view.move_spd;
	}
}
