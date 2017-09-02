#include "fdf.h"

void	quit(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}

int		zoom(int keycode, t_env *e)
{
	if (keycode == 24)
	{
		mlx_clear_window(e->mlx, e->win);
		e->scale += 1;
		e->x = (e->win_width / 2) - ((e->width * e->scale) / 2);
		e->y = (e->win_height / 2) - ((e->height * e->scale) / 2);
		show(e);
		if (e->bres)
			trace(e);
	}
	else if (keycode == 27)
	{
		mlx_clear_window(e->mlx, e->win);
		e->scale -= 1;
		e->x = (e->win_width / 2) - ((e->width * e->scale) / 2);
		e->y = (e->win_height / 2) - ((e->height * e->scale) / 2);
		show(e);
		if (e->bres)
			trace(e);
	}
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 113 || keycode == 53 || keycode == 12)
		quit(e);
	else if (keycode == 49)
		mlx_clear_window(e->mlx, e->win);
	else if (keycode == 13)
		tg_trace(e);
	else if (keycode == 14)
		tg_iso(e);
	else if (keycode == 27 || keycode == 24)
		zoom(keycode, e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	printf("mouse : %d (%d:%d)\n", button, x, y);
	if (button == 1)
		bresenham(e->x, x, e->y, y, e);
	return (0);
}

int		expose_hook(t_env *e)
{
	(void)e;
	show(e);
	return (0);
}
