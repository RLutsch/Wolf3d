
#ifndef WOLF_H
# define WOLF_H

# include <unistd.h>
# include "libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/time.h>

# define H 768
# define W 1024

# define RED 0xFF0000
# define WHITE 0xFFFFFF

typedef struct	s_keys
{
	int			up;
	int			left;
	int			right;
	int			down;
}				t_keys;

typedef struct	s_ray
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		perpwallx;
	double		perpwally;
	double		deltadistx;
	double		deltadisty;
	int			posmapx;
	int			posmapy;
	int			lineheight;
	int			drawstart;
	int			drawend;
}				t_ray;

typedef struct	s_view
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	int			stepx;
	int			stepy;
	t_keys		keys;
	double		rotation_spd;
	double		move_spd;
	double		camerax;
	int			hit;
	int			wallside;
	int			sprint;
}				t_view;

typedef struct	s_map
{
	int			**map;
	int			display;
	int			sizex;
	int			sizey;
}				t_map;

typedef struct	s_img
{
	void		*img;
	char		*d;
	int			bpp;
	int			s;
	int			e;
}				t_img;

typedef struct	s_env
{
	void		*win;
	void		*mlx;
	t_img		img;
	t_view	view;
	t_map		map;
	t_ray		r;
	double		time;
	double		oldtime;
	long int	frametime;
}				t_env;

typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

void			get_map_size(t_env *e, int fd);
void			assimilate(t_env *e, int fd);
void			validate_map(t_env *e, char *pram);
void			compute(t_env *e);
void			dda(t_env *e);
void			raydir(t_env *e);
void			ray(t_env *e, int x);
int				ft_exit(t_env *e);
void			timer(t_env *e);
void			info_to_win(t_env *e);
int				expose_hook(t_env *t);
int				lets_get_wolfy(t_env *e);
int				key_release(int keycode, t_env *e);
int				key_press(int keycode, t_env *e);
void			rotate(t_env *e, char dir);
void			output(t_env *e);
void			move(t_env *e);
void			colours(t_env *e, t_rgb *c);
void			set_colours(t_rgb *colour, int r, int g, int b);
void			pixel(void *mlx, t_img *i, t_coord co, t_rgb *c);
void			draw_vert(int x, t_env *e, t_rgb *c);

#endif
