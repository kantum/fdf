/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rota.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 19:31:07 by qdurot            #+#    #+#             */
/*   Updated: 2017/09/12 19:31:10 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (++i < o->height)
	{
		tmp[i] = (t_point*)malloc((sizeof(t_point) * o->width));
		while (++k < o->width)
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
			e->o.t2[i][k].y = ((e->o.T.x + e->o.T.y) / 2)
							- e->o.T.z * e->o.pitch;
			e->o.t2[i][k].z = e->o.T.z;
			e->o.t2[i][k].color = e->o.T.color;
		}
		k = -1;
	}
	e->o.iso = 1;
}

void	tg_alt(t_env *e)
{
	static int	toggle = 0;

	if (toggle)
	{
		e->alt = 0;
		toggle = 0;
	}
	else
	{
		e->alt = 1;
		toggle = 1;
	}
	if (e->o.iso)
	{
		iso(e);
		draw(e->o.t2, e);
	}
	else
		draw(e->o.tab, e);
}
