#include "fdf.h"

int		main(int argc, char ** argv)
{
	t_env		e;

	if (argc < 1 || argc > 3)
		return (-1);
	if (argc == 2)
		e = *parser(argv[1], &e);
	if (init(&e) < 0)
		return (-1);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
}
