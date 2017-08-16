#include "fdf.h"

int		my_func(int keycode, t_params *param)
{
	if (keycode == 53)
		quit(param);
	if (keycode == 123)
		rectangle(param);
	else if (keycode == 124)
		mlx_clear_window(param->mlx, param->win);
	else if (keycode == 126)
		triangle_right(param);
	else if (keycode == 125)
		triangle_left(param);
	printf("key event %d\n", keycode);
	return (0);
}

int		main()
{
	t_params	*params;
	void		*mlx;
	void 		*win;
	int			x;
	int			y;
	int			x1;
	int			y1;
	int			color;

	x = 100;
	y = 200;
	x1 = 300;
	y1 = 400;
	color = 0xFFF0FF;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "win");

	params = (t_params*)malloc(sizeof(t_params));

	params->mlx = mlx;
	params->win = win;
	params->x = x;
	params->y = y;
	params->x1 = x1;
	params->y1 = y1;
	params->color = color;
	mlx_key_hook(win, my_func, params);
	mlx_loop(mlx);
}
