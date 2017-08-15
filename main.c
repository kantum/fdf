#include "fdf.h"

void	rectangle(t_params *param)
{
	int	x;
	int	y;
	
	y = param->y;
	while (y < param->y1)
	{
		x = param->x;
		while (x < param->x1)
		{
			mlx_pixel_put(param->mlx, param->win, x, y, param->color);
			x++;
		}
		y++;
	}
}

void	triangle_right(t_params *param)
{
	int	x;
	int	y;
	int x1;

	y = param->y;
	x1 = param->x1;
	while (y < param->y1)
	{
		x = x1--;
		while (x < param->x1)
		{
			mlx_pixel_put(param->mlx, param->win, x, y, param->color);
			x++;
		}
		y++;
	}
}

void	triangle_left(t_params *param)
{
	int	x;
	int	y;
	int	x1;

	y = param->y;
	x1 = param->x;
	while (y < param->y1)
	{
		x1++;
		x = param->x;
		while (x < x1)
		{
			mlx_pixel_put(param->mlx, param->win, x, y, param->color);
			x++;
		}
		y++;
	}
}

int		my_func(int keycode, t_params *param)
{
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
	y = 300;
	x1 = 200;
	y1 = 400;
	color = 0xffefd5;

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
