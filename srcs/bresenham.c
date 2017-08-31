#include "fdf.h"

void	horizontal(t_bres *b,int Dx, int x_inc, int y_inc)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = b->x;
	y = b->y;
	while (i < Dx)
	{
		mlx_pixel_put(b->mlx, b->win, x, y, b->color);
		i++;
		x += x_inc;
		b->ex -= b->dy;
		if (b->ex < 0)
		{
			y += y_inc;
			b->ex += b->dx;
		}
	}
}

void	vertical(t_bres *b, int Dy, int x_inc, int y_inc)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = b->x;
	y = b->y;
	while (i < Dy)
	{
		mlx_pixel_put(b->mlx, b->win, x, y, b->color);
		i++;
		y += y_inc;
		b->ey -= b->dx;
		if (b->ey < 0)
		{
			x +=  x_inc;
			b->ey += b->dy;
		}
	}
}

void	bresenham(t_bres *b)
{
	int	x_inc;
	int	y_inc;
	int	Dx;
	int	Dy;

	x_inc = (b->x > b->x1) ? -1 : 1;
	y_inc = (b->y > b->y1) ? -1 : 1;
	b->ex = ft_abs(b->x1 - b->x);
	b->ey = ft_abs(b->y1 - b->y);
	b->dx = 2 * b->ex;
	b->dy = 2 * b->ey;
	Dx = b->ex;
	Dy = b->ey;
	if (Dx < Dy)
		vertical(b, Dy, x_inc, y_inc);
	else
		horizontal(b, Dx, x_inc, y_inc);
}
