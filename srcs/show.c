#include "fdf.h"

void	show(t_env *e)
{
	int			i;
	int			k;

	i = 0;
	k = 0;
	while (i < e->height)
	{
		e->y1 = e->y + i * e->scale;
		while (k < e->width)
		{
			e->x1 = e->x + k * e->scale;
			mlx_pixel_put(e->mlx, e->win, e->x1, e->y1 , e->color);
			k++;
		}
		k = 0;
		i++;
	}
}

void	trace(t_env *e)
{
	(void)(e);
}
