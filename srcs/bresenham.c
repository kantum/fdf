#include "fdf.h"

static void	horizontal(t_env *e, int mx, int x_inc, int y_inc)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = e->x2;
	y = e->y2;
	while (i < mx)
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

static void	vertical(t_env *e, int my, int x_inc, int y_inc)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = e->x2;
	y = e->y2;
	while (i < my)
	{
		put_pixel(e->mlx, e->win, x, y, e->color);
		i++;
		y += y_inc;
		e->ey -= e->dx;
		if (e->ey < 0)
		{
			x += x_inc;
			e->ey += e->dy;
		}
	}
}

void		bresenham(int x, int x1, int y, int y1, t_env *e)
{
	int	x_inc;
	int	y_inc;
	int	mx;
	int	my;

	e->x2 = x;
	e->y2 = y;
	x_inc = (x > x1) ? -1 : 1;
	y_inc = (y > y1) ? -1 : 1;
	e->ex = ft_abs(x1 - x);
	e->ey = ft_abs(y1 - y);
	e->dx = 2 * e->ex;
	e->dy = 2 * e->ey;
	mx = e->ex;
	my = e->ey;
	if (mx < my)
		vertical(e, my, x_inc, y_inc);
	else
		horizontal(e, mx, x_inc, y_inc);
}
