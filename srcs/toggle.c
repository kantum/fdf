/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 19:10:33 by qdurot            #+#    #+#             */
/*   Updated: 2017/09/10 19:10:41 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	cartesian(t_env *e)
{
	free(e->o.t2);
	e->o.t2 = NULL;
	e->o.iso = 0;
	draw(e->o.tab, e);
}

void	tg_rota(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (e->o.iso)
		cartesian(e);
	else
	{
		iso(e);
		e->o.iso = 1;
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
	if (e->o.iso)
		draw(e->o.t2, e);
	else
		draw(e->o.tab, e);
}

int		zoom(int keycode, t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (keycode == 24)
	{
		e->scale += 1;
		e->origin.y -= 10;
		e->origin.x -= 10;
	}
	else if (keycode == 27)
	{
		e->scale -= 1;
		e->origin.y += 10;
		e->origin.x += 10;
	}
	set(e);
	if (e->o.iso)
	{
		iso(e);
		draw(e->o.t2, e);
	}
	else
		draw(e->o.tab, e);
	return (0);
}
