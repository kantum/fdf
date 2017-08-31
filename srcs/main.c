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
		trace(e);
	else if (keycode == 24)
	{
		mlx_clear_window(e->mlx, e->win);
		e->scale += 1;
		show(e);
	}
	else if (keycode == 27)
	{
		mlx_clear_window(e->mlx, e->win);
		e->scale -= 1;
		show(e);
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_bres *b)
{
	printf("mouse : %d (%d:%d)\n", button, x, y);
	if (button == 1)
	{
		b->x1 = x;
		b->y1 = y;
		bresenham(b);
	}
	return (0);
}

int		expose_hook(t_env *e)
{
	(void)e;
	show(e);
	return (0);
}

int		init(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		return (-1);
	e->win_width = 1280;
	e->win_height = 720;
	e->scale = ((e->win_width / e->width) + (e->win_height / e->height)) / 2;
	e->color = 0xCCFFCC;
	e->x = e->win_width / 2 - (e->width / 2 * e->scale);
	e->y = e->win_height / 2 - (e->height / 2 * e->scale);
	e->win = mlx_new_window(e->mlx, e->win_width, e->win_height, "win");
	return (0);
}

int		main(int argc, char **argv)
{
	t_env		*e;

	if (argc < 2 || argc > 3)
		return (-1);
	if (!(e = (t_env*)malloc(sizeof (t_env))))
		return (-1);
	if (argc == 2)
		e = parser(argv[1], e);
	if (init(e) < 0)
		return (-1);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
	free(e);
}
