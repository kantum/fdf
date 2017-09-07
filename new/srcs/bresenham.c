#include "fdf.h"

static void	horizontal(t_env *e, int mx, int x_inc, int y_inc)
{
	t_point	p;
	int	i;

	i = 0;
	p.x = e->b.x;
	p.y = e->b.y;
	p.color = e->color;
	while (i < mx)
	{
		put_pixel(e->mlx, e->win, &p);
		i++;
		p.x += x_inc;
		e->ex -= e->dy;
		if (e->ex < 0)
		{
			p.y += y_inc;
			e->ex += e->dx;
		}
	}
}

static void	vertical(t_env *e, int my, int x_inc, int y_inc)
{
	t_point	p;
	int	i;

	i = 0;
	p.x = e->b.x;
	p.y = e->b.y;
	p.color = e->color;
	while (i < my)
	{
		put_pixel(e->mlx, e->win, &p);
		i++;
		p.y += y_inc;
		e->ey -= e->dx;
		if (e->ey < 0)
		{
			p.x += x_inc;
			e->ey += e->dy;
		}
	}
}

void		bresenham(t_point *a, t_point *b, t_env *e)
{
	int	x_inc;
	int	y_inc;
	int	mx;
	int	my;

	e->b.x = a->x;
	e->b.y = a->y;
	x_inc = (a->x > b->x) ? -1 : 1;
	y_inc = (a->y > b->y) ? -1 : 1;
	e->ex = ft_abs(b->x - a->x);
	e->ey = ft_abs(b->y - a->y);
	e->dx = 2 * e->ex;
	e->dy = 2 * e->ey;
	mx = e->ex;
	my = e->ey;
	if (mx < my)
		vertical(e, my, x_inc, y_inc);
	else
		horizontal(e, mx, x_inc, y_inc);
}

//void bresenham(t_point a, t_point b, t_env *e)
//{
//	t_bres br;
//
//	br.dx = abs(b.x-a.x);
//	br.sx = a.x<b.x ? 1 : -1;
//	br.dy = abs(b.y-a.y);
//	br.sy = a.y<b.y ? 1 : -1;
//	br.err = (br.dx > br.dy ? br.dx : -br.dy) / 2;
//	for(;;)
//	{
//		put_pixel(e->mlx, e->win, &a);
//		if (a.x == b.x && a.y == b.y)
//			break;
//		br.e2 = br.err;
//		if (br.e2 > -br.dx)
//			br.err -= br.dy; a.x += br.sx;
//		if (br.e2 < br.dy)
//			br.err += br.dx; a.y += br.sy;
//	}
//}
