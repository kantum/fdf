#include "fdf.h"

void	quit(t_env *e)
{
	mlx_destroy_window (e->mlx, e->win);
	exit (0);
}

void	rectangle(t_env *e)
{
	int	x;
	int	y;
	
	y = e->y;
	while (y < e->y1)
	{
		x = e->x;
		while (x < e->x1)
		{
			mlx_pixel_put(e->mlx, e->win, x, y, e->color);
			x++;
		}
		y++;
	}
}

void	triangle_right(t_env *e)
{
	int	x;
	int	y;
	int x1;

	y = e->y;
	x1 = e->x1;
	while (y < e->y1)
	{
		x = x1--;
		while (x < e->x1)
		{
			mlx_pixel_put(e->mlx, e->win, x, y, e->color);
			x++;
		}
		y++;
	}
}

void	triangle_left(t_env *e)
{
	int	x;
	int	y;
	int	x1;

	y = e->y;
	x1 = e->x;
	while (y < e->y1)
	{
		x1++;
		x = e->x;
		while (x < x1)
		{
			mlx_pixel_put(e->mlx, e->win, x, y, e->color);
			x++;
		}
		y++;
	}
}

void	red_point(t_env *e)
{
	mlx_pixel_put(e->mlx, e->win, e->x, e->y, 0xFF0000);
	mlx_pixel_put(e->mlx, e->win, e->x1, e->y1, 0xFF0000);
}

//void	trace_it(t_env *e, int x_inc, int y_inc)
//{
//	int	x;
//	int	y;
//
//	x = e->x;
//	y = e->y;
//}

void	trace(t_env *e)
{
	int	x;
	int	y;

	int	x_inc;
	int	y_inc;

	x = e->x;
	y = e->y;
	x_inc = (x > e->x1) ? -1 : 1;
	y_inc = (y > e->y1) ? -1 : 1;

	int	dx;
	int	dy;
	int	ex;
	int	ey;
	int	i;

	int	Dx;
	int	Dy;

	i = 0;
	ex = ft_abs(e->x1 - x);
	ey = ft_abs(e->y1 - y);
	dx = 2 * ex;
	dy = 2 * ft_abs(e->y1 - y);
	Dx = ex;
	Dy = ey;
	if (dx > Dy)
	{
		while (i < Dx)
		{
			mlx_pixel_put(e->mlx, e->win, x, y, e->color);
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
			mlx_pixel_put(e->mlx, e->win, x, y, e->color);
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
