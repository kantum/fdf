#include "fdf.h"

int		isometric(t_env *e)
{
	int		i;
	int		k;
	int		l;

	i = -1;
	k = -1;
	l = -1;
	if (!(e->m = (t_point*)malloc(sizeof(t_point) * e->totalsize)))
		return (0);
	while (++i < e->height)
	{
		e->b.y = e->y + i * e->scale;
		while (++k < e->width)
		{
			e->b.x = e->x + k * e->scale;
			e->m[++l].x = e->b.x - e->b.y + e->x;
			e->m[l].y = (e->b.x + e->b.y) / 2;
			e->m[l].z = (e->tab[i][k]);
			e->m[l].color = e->color;
		}
		k = -1;
	}
	e->iso = 1;
	return (1);
}

void	cartesian(t_env *e)
{
	free(e->m);
	e->m = NULL;
	e->iso = 0;
}

void	tg_iso(t_env *e)
{
	if (e->iso)
	{
		mlx_clear_window(e->mlx, e->win);
		cartesian(e);
		if (e->bres)
			trace(e);
		show(e);
		e->iso = 0;
	}
	else
	{
		mlx_clear_window(e->mlx, e->win);
		isometric(e);
		if (e->bres)
			trace(e);
		show(e);
		e->iso = 1;
	}
}

void	tg_trace(t_env *e)
{
	if (e->bres)
	{
		mlx_clear_window(e->mlx, e->win);
		show(e);
		e->bres = 0;
	}
	else
	{
		trace(e);
		e->bres = 1;
	}
}
