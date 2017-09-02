#include "fdf.h"

int		init(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		return (-1);
	e->win_width = 1280;
	e->win_height = 720;
	e->scale = ((e->win_width / e->width) + (e->win_height / e->height)) / 4;
	e->color = 0xCCFFCC;
	e->bres = 0;
	e->x = (e->win_width / 2) - ((e->width * e->scale) / 2);
	e->y = (e->win_height / 2) - ((e->height * e->scale) / 2);
	e->win = mlx_new_window(e->mlx, e->win_width, e->win_height, "win");
	e->m = NULL;
	return (0);
}

int		main(int argc, char **argv)
{
	t_env		e;
	if (argc < 2 || argc > 3)
		return (-1);
	if (argc == 2)
		parser(argv[1], &e);
	if (init(&e) < 0)
		return (-1);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	free(&e);
}
