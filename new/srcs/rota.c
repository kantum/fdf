#include "fdf.h"

t_point	**tab_dup(t_obj *o)
{
	int		i;
	int		k;
	t_point	**tmp;

	i = -1;
	k = -1;
	if (!(tmp = (t_point**)malloc(sizeof(t_point*) * o->height)))
		return (NULL);
	while(++i < o->height)
	{
		tmp[i] = (t_point*)malloc((sizeof(t_point) * o->width));
		while(++k < o->width)
		{
			tmp[i][k].x = o->T.x;
			tmp[i][k].y = o->T.y;
			tmp[i][k].z = o->T.z;
			tmp[i][k].color = o->T.color;
		}
		k = -1;
	}
	return (tmp);
}

void	z_rot(t_env *e, int angle)
{
	int		i;
	int		k;
	t_point	**tab;

	i = -1;
	k = -1;
	init_img(e);
	tab = tab_dup(&e->o);
	set(e);
	while(++i < e->o.height)
	{
		while(++k < e->o.width)
		{
			T.x = e->o.T.x * cos(angle) - e->o.T.y * sin(angle);
			T.y = e->o.T.x * sin(angle) + e->o.T.y * cos(angle);
			T.z = e->o.T.z;
			T.color = e->o.T.color;
		}
		k = -1;
	}
	draw(tab, e);
	free(tab);
}

void	x_rot(t_env *e, int angle)
{
	int		i;
	int		k;
	t_point	**tab;

	i = -1;
	k = -1;
	init_img(e);
	tab = tab_dup(&e->o);
	set(e);
	while(++i < e->o.height)
	{
		while(++k < e->o.width)
		{
			T.x = e->o.T.x;
			T.y = e->o.T.y * cos(angle) - e->o.T.z * sin(angle);
			T.z = e->o.T.y * sin(angle) + e->o.T.z * cos(angle);
			T.color = e->o.T.color;
		}
		k = -1;
	}
	draw(tab, e);
	free(tab);
}

void	y_rot(t_env *e, int angle)
{
	int		i;
	int		k;
	t_point	**tab;

	i = -1;
	k = -1;
	init_img(e);
	tab = tab_dup(&e->o);
	set(e);
	while(++i < e->o.height)
	{
		while(++k < e->o.width)
		{
			T.x = e->o.T.z * sin(angle) + e->o.T.x * cos(angle);
			T.y = e->o.T.y;
			T.z = e->o.T.z * cos(angle) - e->o.T.x * sin(angle);
			T.color = e->o.T.color;
		}
		k = -1;
	}
	draw(tab, e);
	free(tab);
}

void	iso(t_env *e)
{
	int		i;
	int		k;

	i = -1;
	k = -1;
	init_img(e);
	e->o.t2 = tab_dup(&e->o);
	set(e);
	while(++i < e->o.height)
	{
		while(++k < e->o.width)
		{
			e->o.t2[i][k].x = e->o.T.x - e->o.T.y + e->origin.x;
			e->o.t2[i][k].y = (e->o.T.x + e->o.T.y) / 2;
			e->o.t2[i][k].z = e->o.T.z = e->o.T.z;
			e->o.t2[i][k].color = e->o.T.color;
		}
		k = -1;
	}
	e->o.rota = 1;
}

void	rota(t_env *e, int axe, int a)
{
	if (axe == 0)
		iso(e);
	else if (axe == 1)
		z_rot(e, a);
	else if (axe == 2)
		x_rot(e, a);
	else if (axe == 3)
		y_rot(e, a);
}

void	cartesian(t_env *e)
{
	free(e->o.t2);
	e->o.t2 = NULL;
	e->o.rota = 0;
	draw(e->o.tab, e);
}

void	tg_rota(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (e->o.rota)
		cartesian(e);
	else
	{
		rota(e, 0, 0);
		e->o.rota = 1;
		draw(e->o.t2, e);
	}
}

void	tg_trace(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (e->o.bres)
		e->o.bres = 0;
	else
		e->o.bres = 1;
	if (e->o.rota)
		draw(e->o.t2, e);
	else
		draw(e->o.tab, e);
}
