#include "fdf.h"

void	quit(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}

/*
**		Keyboard inputs hooked here
*/

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 113 || keycode == 53 || keycode == 12)
		quit(e);
	else if (keycode == 49)
		mlx_clear_window(e->mlx, e->win);
	return (0);
}

/*
**		Mouse inputs hooked here
*/

int		mouse_hook(int button, int x, int y, t_env *e)
{
	printf("mouse : %d (%d:%d)\n", button, x, y);
	if (button == 1)
	{
		e->x1 = x;
		e->y1 = y;
		bresenham(e);
		e->x = x;
		e->y = y;
	}
	return (0);
}

/*
**		Expose
*/

int		expose_hook(t_env *e)
{
	(void)e;
	//return (mlx_clear_window(e->mlx, e->win));
	return (0);
}

void	show(t_env *e)
{
	int			i;
	int			k;

	i = 0;
	k = 0;
	while (e->tab[i])
	{
		while (e->tab[i][k])
		{
			e->x1 = e->x + e->scale;
			e->y1 = e->y;
			mlx_pixel_put(e->mlx, e->win, e->x, e->y, e->color);
			k++;
		}
		e->y += e->scale;
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_env		*e;

	if (!(e = (t_env*)malloc(sizeof (t_env))))
		return (-1);
	if (argc == 2)
		e = parser(argv[1], e);
	if (!(e->mlx = mlx_init()))
		return (-1);
	e->win_width = 1280;
	e->win_height = 800;
	e->scale = 10;
	e->color = 0xCCFFCC;
	e->x = e->win_width/2 - e->width/2;
	e->x = (e->win_width/2) + ((e->width/2) * e->scale);
	e->y = (e->win_height/2) + ((e->height/2) * e->scale);
	e->win = mlx_new_window(e->mlx, 1280, 800, "win");
	show(e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	//mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
	free(e);
}
