/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 19:10:21 by qdurot            #+#    #+#             */
/*   Updated: 2017/09/10 19:10:41 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_point(t_point *p)
{
	p->x = 0;
	p->y = 0;
	p->z = 0;
	p->color = 0xFFFFFF;
}

void	init_img(t_env *e)
{
	free(e->img);
	e->img = mlx_new_image(e->mlx, e->win_width, e->win_height);
	e->data = (int *)mlx_get_data_addr(e->img, &e->bpp, &e->size, &e->endian);
}

int		init(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		return (-1);
	e->win_width = WIDTH;
	e->win_height = HEIGHT;
	e->o.bres = 1;
	e->scale = (e->win_width / e->o.width + e->win_height / e->o.height) / 4;
	e->origin.x = (e->win_width / 2) - ((e->o.width * e->scale) / 2);
	e->origin.y = (e->win_height / 2) - ((e->o.height * e->scale) / 2);
	e->win = mlx_new_window(e->mlx, e->win_width, e->win_height, "win");
	e->o.pitch = 1;
	e->axe = 0;
	e->color = 0xFFFFFF;
	return (0);
}

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
