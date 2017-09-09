#include "fdf.h"

void	quit(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 113 || keycode == 53 || keycode == 12)
		quit(e);
	else if (keycode == 49)
		mlx_clear_window(e->mlx, e->win);
	else if (keycode == 13)
		tg_rota(e);
	else if (keycode == 14)
		tg_trace(e);
	else if (keycode >= 123 && keycode <= 126)
		move(keycode, e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	(void)button;
	(void)x;
	(void)y;
	(void)e;
	return (0);
}

int		expose_hook(t_env *e)
{
	(void)e;
	set(e);
	rota(e, 0, 0);
	init_img(e);
	draw(e->o.t2, e);
	return (0);
}
