#include "fdf.h"

void	put_pixel(void *mlx, void *win, int x, int y, int color)
{
	mlx_pixel_put(mlx, win, x, y, color);
}

void	trace_m(t_env *e)
{
	int			i;
	t_point		right;
	t_point		down;

	i = 0;
	while (i < e->totalsize - 1)
	{
		if (i < e->totalsize - e->width)
		{
			down = e->m[i + e->width];
			if (i < e->totalsize - 2 * e->width)
			down.y -= e->m[i + e->width].z;
			bresenham(e->m[i].x, down.x, e->m[i].y - e->m[i].z, down.y, e);
		}
		right = e->m[i + 1];
		right.y -= e->m[i + 1].z;
		if ((i + 1) % e->width)
			bresenham(e->m[i].x, right.x, e->m[i].y - e->m[i].z, right.y, e);
		i++;
	}
}

void	show_m(t_env *e)
{
	int		i;

	i = -1;
	mlx_clear_window(e->mlx, e->win);
	while (++i < e->totalsize)
	{
		put_pixel(e->mlx, e->win, e->m[i].x, e->m[i].y - e->m[i].z, e->color);
	}
}

void	show(t_env *e)
{
	int			i;
	int			k;

	i = 0;
	k = 0;
	if (e->m)
	{
		show_m(e);
		return ;
	}
	while (i < e->height)
	{
		e->y1 = (e->y + i * e->scale);
		while (k < e->width)
		{
			e->x1 = e->x + k * e->scale;
			put_pixel(e->mlx, e->win, e->x1, e->y1, e->color);
			k++;
		}
		k = 0;
		i++;
	}
}

void	trace(t_env *e)
{
	int			i;
	int			k;
	int			x2;
	int			y2;

	i = 0;
	k = 0;
	if (e->m)
	{
		trace_m(e);
		return ;
	}
	while (i < e->height)
	{
		e->y1 = e->y + i * e->scale;
		while (k < e->width)
		{
			e->x1 = e->x + k * e->scale;
			x2 = e->x1 + e->scale;
			if (k < e->width - 1)
				bresenham(e->x1, x2, e->y1, e->y1, e);
			y2 = e->y1 + e->scale;
			if (i < e->height - 1)
				bresenham(e->x1, e->x1, e->y1, y2, e);
			k++;
		}
		k = 0;
		i++;
	}
}
