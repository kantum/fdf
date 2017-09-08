#include "fdf.h"

void	put_pixel(void *mlx, void *win, t_point *p)
{
	mlx_pixel_put(mlx, win, p->x, p->y, p->color);
}

void	color_p(t_point *p)
{
	p->color = 0xFFFFFF;
}

void	draw(t_env *e)
{
	int	i;
	int	k;

	i = -1;
	k = -1;
	while(++i < e->o.height)
	{
		while(++k < e->o.width)
		{
			color_p(&e->o.tab[i][k]);
			put_pixel(e->mlx, e->win, &e->o.tab[i][k]);
		}
		k = -1;
	}
}


void	set(t_env *e)
{
	int	i;
	int	k;

	i = -1;
	k = -1;
	while(++i < e->o.height)
	{
		while(++k < e->o.width)
		{
			e->o.tab[i][k].x = (e->origin.x + k * e->scale);
			e->o.tab[i][k].y = (e->origin.y + i * e->scale);
			color_p(&e->o.tab[i][k]);
			put_pixel(e->mlx, e->win, &e->o.tab[i][k]);
		}
		k = -1;
	}
}
