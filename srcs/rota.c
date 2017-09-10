/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rota.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 19:10:30 by qdurot            #+#    #+#             */
/*   Updated: 2017/09/10 19:10:41 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	while (++i < e->o.height)
	{
		while (++k < e->o.width)
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
	while (++i < e->o.height)
	{
		while (++k < e->o.width)
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
	while (++i < e->o.height)
	{
		while (++k < e->o.width)
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
	while (++i < e->o.height)
	{
		while (++k < e->o.width)
		{
			e->o.t2[i][k].x = e->o.T.x - e->o.T.y + e->origin.x + e->scale;
			e->o.t2[i][k].y = ((e->o.T.x + e->o.T.y) / 2) \
							- e->o.T.z * e->o.pitch;
			e->o.t2[i][k].z = e->o.T.z;
			e->o.t2[i][k].color = e->o.T.color;
		}
		k = -1;
	}
	e->o.iso = 1;
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
