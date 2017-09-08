#include "fdf.h"

void	init_point(t_point *p)
{
	p->x = 0;
	p->y = 0;
	p->z = 0;
	p->color = 0xFFFFFF;
}

int		init(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		return (-1);
	e->win_width = 1280;
	e->win_height = 800;
	e->o.bres = 0;
	e->scale = ((e->win_width / e->o.width) + (e->win_height / e->o.height)) / 3;
	e->origin.x = (e->win_width / 2) - ((e->o.width * e->scale) / 2);
	e->origin.y = (e->win_height / 2) - ((e->o.height * e->scale) / 2);
	e->win = mlx_new_window(e->mlx, e->win_width, e->win_height, "win");
	e->o.pitch = 1;
	return (0);
}
