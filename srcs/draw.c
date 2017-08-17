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

void	red_point(t_params *param)
{
	mlx_pixel_put(param->mlx, param->win, param->x, param->y, 0xFF0000);
	mlx_pixel_put(param->mlx, param->win, param->x1, param->y1, 0xFF0000);
}

void	trace_it(t_params *param, int x_inc, int y_inc)
{
	int	x;
	int	y;

	x = param->x;
	y = param->y;
}

void	trace(t_params *param)
{
	int	x;
	int	y;

	int	x_inc;
	int	y_inc;

	x = param->x;
	y = param->y;
	x_inc = (x > param->x1) ? -1 : 1;
	y_inc = (y > param->y1) ? -1 : 1;

	int	dx;
	int	dy;
	int	ex;
	int	ey;
	int	i;

	int	Dx;
	int	Dy;

	i = 0;
	ex = ft_abs(param->x1 - x);
	ey = ft_abs(param->y1 - y);
	dx = 2 * ex;
	dy = 2 * ft_abs(param->y1 - y);
	Dx = ex;
	Dy = ey;
	if (Dx > Dy)
	{
		while (i < Dx)
		{
			mlx_pixel_put(param->mlx, param->win, x, y, param->color);
			i++;
			x += x_inc;
			ex -= dy;
			if (ex < 0)
			{
				y += y_inc;
				ex += dx;
			}
		}
	}
	else
	{
		while (i < Dy)
		{
			mlx_pixel_put(param->mlx, param->win, x, y, param->color);
			i++;
			y += y_inc;
			ey -= dx;
			if (ex < 0)
			{
				x +=  x_inc;
				ey += dy;
			}
		}
	}
}
