/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 19:10:13 by qdurot            #+#    #+#             */
/*   Updated: 2017/09/10 19:10:41 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_point *p, t_env *e)
{
	if (p->y < e->win_height && p->x < e->win_width &&
		p->y >= 0 && p->x >= 0)
		e->data[p->y * e->win_width + p->x] = p->color;
}

void	color_p(t_point *p, t_env *e)
{
	p->color = e->color;
}

void	trace(t_point **tab, t_env *e)
{
	int			i;
	int			k;
	t_point		right;
	t_point		down;

	i = -1;
	k = -1;
	while (++i < e->o.height)
	{
		while (++k < e->o.width)
		{
			if (i + 1 < e->o.height)
			{
				down = tab[i + 1][k];
				bresenham(T, down, e);
			}
			if (k + 1 < e->o.width)
			{
				right = tab[i][k + 1];
				bresenham(T, right, e);
			}
		}
		k = -1;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	draw(t_point **tab, t_env *e)
{
	int	i;
	int	k;

	i = -1;
	k = -1;
	mlx_clear_window(e->mlx, e->win);
	init_img(e);
	if (e->o.bres)
		trace(tab, e);
	while (++i < e->o.height)
	{
		while (++k < e->o.width)
		{
			color_p(&T, e);
			put_pixel(&T, e);
		}
		k = -1;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	set(t_env *e)
{
	int	i;
	int	k;

	i = -1;
	k = -1;
	while (++i < e->o.height)
	{
		while (++k < e->o.width)
		{
			e->o.T.x = (e->origin.x + k * e->scale);
			e->o.T.y = (e->origin.y + i * e->scale);
			color_p(&e->o.T, e);
		}
		k = -1;
	}
}
