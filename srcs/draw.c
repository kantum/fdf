#include "fdf.h"

void	quit(t_params *param)
{
	mlx_destroy_window (param->mlx, param->win);
	exit (0);
}

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
