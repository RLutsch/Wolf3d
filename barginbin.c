
#include "wolf.h"

void	info_to_win(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 512, 20, RED, "Wolf3D...ish");
	mlx_string_put(e->mlx, e->win, 900, 30, RED, "Keys:");
	mlx_string_put(e->mlx, e->win, 900, 60, WHITE, "Arrow keys");
	mlx_string_put(e->mlx, e->win, 30, 30, RED, "Exit Wolf:");
	mlx_string_put(e->mlx, e->win, 30, 60, WHITE, "ESC key");
}

void	timer(t_env *e)
{
	struct timeval time;

	e->oldtime = e->time;
	gettimeofday(&time, 0);
	e->time = time.tv_sec * 1000 + time.tv_usec / 1000;
	e->frametime = e->time - e->oldtime;
	e->view.move_spd = e->frametime * 0.003;
	e->view.rotation_spd = e->frametime * 0.003;
}

int		ft_exit(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->img.img);
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
	return (0);
}
