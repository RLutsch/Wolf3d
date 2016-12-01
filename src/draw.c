/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:59:28 by rlutsch           #+#    #+#             */
/*   Updated: 2016/12/01 10:59:31 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	set_colours(t_rgb *colour, int r, int g, int b)
{
	colour->r = r;
	colour->g = g;
	colour->b = b;
}

void	pixel(void *mlx, t_img *i, t_coord co, t_rgb *c)
{
	if (i->e)
	{
		i->d[co.y * i->s + co.x * i->bpp / 8] = mlx_get_color_value(mlx, c->r);
		i->d[co.y * i->s + co.x * i->bpp / 8 + 1] =
			mlx_get_color_value(mlx, c->g);
		i->d[co.y * i->s + co.x * i->bpp / 8 + 2] =
			mlx_get_color_value(mlx, c->b);
	}
	else
	{
		i->d[co.y * i->s + i->bpp / 8 * co.x] = mlx_get_color_value(mlx, c->b);
		i->d[co.y * i->s + i->bpp / 8 * co.x + 1] =
			mlx_get_color_value(mlx, c->g);
		i->d[co.y * i->s + i->bpp / 8 * co.x + 2] =
			mlx_get_color_value(mlx, c->r);
	}
}

void	draw_vert(int x, t_env *e, t_rgb *colour)
{
	t_coord		co;
	t_rgb		top_bottom;

	co.x = x;
	e->img.d = mlx_get_data_addr(e->img.img, &e->img.bpp, &e->img.s, &e->img.e);
	set_colours(&top_bottom, 64, 64, 64);
	co.y = 0;
	while (co.y < e->r.drawstart)
	{
		pixel(e, &(e->img), co, &top_bottom);
		co.y++;
	}
	co.y = e->r.drawstart;
	while (co.y < e->r.drawend)
	{
		pixel(e, &(e->img), co, colour);
		co.y++;
	}
	set_colours(&top_bottom, 128, 128, 128);
	co.y = e->r.drawend;
	while (co.y < H)
	{
		pixel(e, &(e->img), co, &top_bottom);
		co.y++;
	}
}

void	colours(t_env *e, t_rgb *colour)
{
	if (e->view.wallside == 0)
		if (e->view.stepx < 0)
			set_colours(colour, 0, 0, 255);
		else
			set_colours(colour, 0, 102, 0);
	else if (e->view.stepy < 0)
		set_colours(colour, 0, 0, 128);
	else
		set_colours(colour, 0, 204, 0);
}
