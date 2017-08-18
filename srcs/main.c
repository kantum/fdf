#include "fdf.h"

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		quit(e);
	if (keycode == 123)
	{
		trace(e);
		red_point(e);
	}
	else if (keycode == 124)
		mlx_clear_window(e->mlx, e->win);
	else if (keycode == 126)
		triangle_right(e);
	else if (keycode == 125)
		triangle_left(e);
	//printf("key event %d\n", keycode);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	printf("mouse : %d (%d:%d)\n", button, x, y);
	if (button == 1)
	{
		e->x1 = x;
		e->y1 = y;
		trace(e);
	}
	return (0);
}
int		expose_hook(t_env *e)
{
		return (mlx_clear_window(e->mlx, e->win));
}

int		main()
{
	t_env		*e;
	int			x;
	int			y;
	int			x1;
	int			y1;
	int			color;

	x = 100;
	y = 400;
	x1 = 500;
	y1 = 300;
	color = 0xFFF0FF;

	e = (t_env*)malloc(sizeof(t_env));

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 800, 600, "win");
	e->x = x;
	e->y = y;
	e->x1 = x1;
	e->y1 = y1;
	e->color = color;
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
}
