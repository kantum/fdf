#include "fdf.h"

void	put_pixel_(void *mlx, void *win, int x, int y, int color)
{
	mlx_pixel_put(mlx, win, x, y, color);
}

void	put_pixel(void *mlx, void *win, t_point *p)
{
	mlx_pixel_put(mlx, win, p->x, p->y, p->color);
}

void	trace_m(t_env *e)
{
	int			i;
	t_point		right;
	t_point		down;

	i = -1;
	while (++i < e->totalsize - 1)
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
	}
}

void	show_m(t_env *e)
{
	int		i;
	t_point	p;

	i = -1;
	mlx_clear_window(e->mlx, e->win);
	while (++i < e->totalsize)
	{
		p = e->m[i];
		p.y -= e->m[i].z;
		put_pixel(e->mlx, e->win, &p);
	}
}

void	show(t_env *e)
{
	int			i;
	int			k;
	t_point		p;

	i = 0;
	k = 0;
	if (e->m)
	{
		show_m(e);
		return ;
	}
	p.color = e->color;
	while (i < e->height)
	{
		p.y = (e->y + i * e->scale);
		while (k < e->width)
		{
			p.x = e->x + k * e->scale;
			put_pixel(e->mlx, e->win, &p);
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

	i = -1;
	k = -1;
	if (e->m)
	{
		trace_m(e);
		return ;
	}
	while (++i < e->height)
	{
		e->b.y = e->y + i * e->scale;
		while (++k < e->width)
		{
			e->b.x = e->x + k * e->scale;
			e->x2 = e->b.x + e->scale;
			if (k < e->width - 1)
				bresenham(e->b.x, e->x2, e->b.y, e->b.y, e);
			e->y2 = e->b.y + e->scale;
			if (i < e->height - 1)
				bresenham(e->b.x, e->b.x, e->b.y, e->y2, e);
		}
		k = -1;
	}
}
