#include "fdf.h"

void	init_point(t_point *p)
{
	p->x = 0;
	p->y = 0;
	p->z = 0;
	p->color = 0xCCFFCC;
}

int		init(t_env *e, t_obj *o)
{
	if (!(e->mlx = mlx_init()))
		return (-1);
	e->win_width = 1280;
	e->win_height = 800;
	e->scale = 10;// ((e->win_width / o->width) + (e->win_height / o->height)) / 4;
	o->bres = 0;
	e->origin.x = 10;//(e->win_width / 2) - ((o->width * e->scale) / 2);
	e->origin.y = 10;//(e->win_height / 2) - ((o->height * e->scale) / 2);
	e->win = mlx_new_window(e->mlx, e->win_width, e->win_height, "win");
	o->pitch = 1;
	return (0);
}
