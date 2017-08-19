#include "fdf.h"

void	horizontal(t_env *e,int Dx, int x_inc, int y_inc)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = e->x;
	y = e->y;
	while (i < Dx)
	{
		mlx_pixel_put(e->mlx, e->win, x, y, e->color);
		i++;
		x += x_inc;
		e->ex -= e->dy;
		if (e->ex < 0)
		{
			y += y_inc;
			e->ex += e->dx;
		}
	}
}

void	vertical(t_env *e, int Dy, int x_inc, int y_inc)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = e->x;
	y = e->y;
	while (i < Dy)
	{
		mlx_pixel_put(e->mlx, e->win, x, y, e->color);
		i++;
		y += y_inc;
		e->ey -= e->dx;
		if (e->ey < 0)
		{
			x +=  x_inc;
			e->ey += e->dy;
		}
	}
}

void	bresenham(t_env *e)
{
	int	x_inc;
	int	y_inc;
	int	Dx;
	int	Dy;

	x_inc = (e->x > e->x1) ? -1 : 1;
	y_inc = (e->y > e->y1) ? -1 : 1;
	e->ex = ft_abs(e->x1 - e->x);
	e->ey = ft_abs(e->y1 - e->y);
	e->dx = 2 * e->ex;
	e->dy = 2 * e->ey;
	Dx = e->ex;
	Dy = e->ey;
	if (Dx < Dy)
		vertical(e, Dy, x_inc, y_inc);
	else
		horizontal(e, Dx, x_inc, y_inc);
}
