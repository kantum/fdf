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
		rota(e, 10);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	t_point	a;
	t_point	b;


	init_point(&a);
	printf("mouse : %d (%d:%d)\n", button, x, y);
	if (button == 1)
	{
		b.x = x;
		b.y = y;
		put_pixel(e->mlx, e->win, &b);
		bresenham(a,b, e);
	}
	return (0);
}

int		expose_hook(t_env *e)
{
	(void)e;
	set(e);
	return (0);
}
