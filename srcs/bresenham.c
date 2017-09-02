#include "fdf.h"

static void	horizontal(t_env *e, int Dx, int x_inc, int y_inc)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = e->x2;
	y = e->y2;
	while (i < Dx)
	{
		put_pixel(e->mlx, e->win, x, y, e->color);
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

static void	vertical(t_env *e, int Dy, int x_inc, int y_inc)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = e->x2;
	y = e->y2;
	while (i < Dy)
	{
		put_pixel(e->mlx, e->win, x, y, e->color);
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

void		bresenham(int x, int x1, int y, int y1, t_env *e)
{
	int	x_inc;
	int	y_inc;
	int	Dx;
	int	Dy;

	e->x2 = x;
	e->y2 = y;
	x_inc = (x > x1) ? -1 : 1;
	y_inc = (y > y1) ? -1 : 1;
	e->ex = ft_abs(x1 - x);
	e->ey = ft_abs(y1 - y);
	e->dx = 2 * e->ex;
	e->dy = 2 * e->ey;
	Dx = e->ex;
	Dy = e->ey;
	if (Dx < Dy)
		vertical(e, Dy, x_inc, y_inc);
	else
		horizontal(e, Dx, x_inc, y_inc);
}
