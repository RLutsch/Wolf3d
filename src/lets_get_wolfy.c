/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_get_wolfy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:59:54 by rlutsch           #+#    #+#             */
/*   Updated: 2016/12/01 11:00:00 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	ray(t_env *e, int x)
{
	e->view.camerax = 2 * x / (double)(W) - 1;
	e->r.posx = e->view.posx;
	e->r.posy = e->view.posy;
	e->r.dirx = e->view.dirx + e->r.planex * e->view.camerax;
	e->r.diry = e->view.diry + e->r.planey * e->view.camerax;
	e->r.posmapx = (int)e->r.posx;
	e->r.posmapy = (int)e->r.posy;
	e->r.deltadistx = sqrt(1 + (e->r.diry * e->r.diry)
			/ (e->r.dirx * e->r.dirx));
	e->r.deltadisty = sqrt(1 + (e->r.dirx * e->r.dirx)
			/ (e->r.diry * e->r.diry));
	e->view.hit = 0;
}

void	ray_direction(t_env *e)
{
	if (e->r.dirx < 0)
	{
		e->view.stepx = -1;
		e->r.perpwallx = (e->r.posx - e->r.posmapx) * e->r.deltadistx;
	}
	else
	{
		e->view.stepx = 1;
		e->r.perpwallx = (e->r.posmapx + 1.0 - e->r.posx) * e->r.deltadistx;
	}
	if (e->r.diry < 0)
	{
		e->view.stepy = -1;
		e->r.perpwally = (e->r.posy - e->r.posmapy) * e->r.deltadisty;
	}
	else
	{
		e->view.stepy = 1;
		e->r.perpwally = (e->r.posmapy + 1.0 - e->r.posy) * e->r.deltadisty;
	}
}

void	dda(t_env *e)
{
	while (e->view.hit == 0)
	{
		if (e->r.perpwallx < e->r.perpwally)
		{
			e->r.perpwallx += e->r.deltadistx;
			e->r.posmapx += e->view.stepx;
			e->view.wallside = 0;
		}
		else
		{
			e->r.perpwally += e->r.deltadisty;
			e->r.posmapy += e->view.stepy;
			e->view.wallside = 1;
		}
		if (e->map.map[e->r.posmapx][e->r.posmapy] > 0)
			e->view.hit = 1;
	}
}

void	compute(t_env *e)
{
	double distwall;

	if (e->view.wallside == 0)
		distwall = fabs((e->r.posmapx - e->r.posx
					+ (1 - e->view.stepx) / 2) / e->r.dirx);
	else
		distwall = fabs((e->r.posmapy - e->r.posy
					+ (1 - e->view.stepy) / 2) / e->r.diry);
	e->r.lineheight = abs((int)(H / distwall));
	e->r.drawstart = (-1 * (e->r.lineheight)) / 2 + H / 2;
	if (e->r.drawstart < 0)
		e->r.drawstart = 0;
	e->r.drawend = e->r.lineheight / 2 + H / 2;
	if (e->r.drawend >= H)
		e->r.drawend = H - 1;
}

int		lets_get_wolfy(t_env *e)
{
	t_rgb	c;
	int		x;

	if (e->img.img != 0)
	{
		mlx_destroy_image(e->mlx, e->img.img);
		e->img.img = 0;
	}
	e->img.img = mlx_new_image(e->mlx, W, H);
	x = 0;
	while (x < W)
	{
		ray(e, x);
		ray_direction(e);
		dda(e);
		compute(e);
		colours(e, &c);
		draw_vert(x, e, &c);
		x++;
	}
	timer(e);
	move(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	info_to_win(e);
	return (0);
}
