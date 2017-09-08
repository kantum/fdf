#include "fdf.h"

void	put_pixel(void *mlx, void *win, t_point *p)
{
	mlx_pixel_put(mlx, win, p->x, p->y, p->color);
}

void	draw(t_obj *o, t_env *e)
{
	int	i;
	int	k;

	i = -1;
	k = -1;
	while(++i < o->height)
	{
		while(++k < o->width)
		{
			o->tab[i][k].x = (e->origin.x + i * e->scale);
			o->tab[i][k].y = (e->origin.y + k * e->scale);
			put_pixel(e->mlx, e->win, &o->tab[i][k]);
		}
		k = -1;
	}
}
