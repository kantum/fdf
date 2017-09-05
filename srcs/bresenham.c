#include "fdf.h"

static void	horizontal(t_env *e, int mx, int x_inc, int y_inc)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = e->b.x;
	y = e->b.y;
	while (i < mx)
	{
		put_pixel_(e->mlx, e->win, x, y, e->color);
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
	x = e->b.x;
	y = e->b.y;
	while (i < my)
	{
		put_pixel_(e->mlx, e->win, x, y, e->color);
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

	e->b.x = x;
	e->b.y = y;
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


//void bresengam(t_point *a, t_point *b, t_env *e)
//{
//  int	dx = abs(b->x-a->x);
//  int	sx = a->x<b->x ? 1 : -1;
//  int	dy = abs(b->y-a->y);
//  int	sy = a->y<b->y ? 1 : -1; 
//  int	err = (dx>dy ? dx : -dy)/2;
//  int	e2;
//
//  dx = abs(b->x-a->x);
//  sx = a->x<b->x ? 1 : -1;
//  dy = abs(b->y-a->y);            
//  sy = a->y<b->y ? 1 : -1; 
//  err = (dx>dy ? dx : -dy)/2;
//  for(;;){
//	  put_pixel(e->mlx, e->win, a);
//	  if (a->x == b->x && a->y == b->y) break;
//	  e2 = err;
//	  if (e2 > -dx) { err -= dy; a->x += sx; }
//	  if (e2 < dy) { err += dx; a->y += sy; }
//  }
//}
