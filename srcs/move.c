/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 19:10:26 by qdurot            #+#    #+#             */
/*   Updated: 2017/09/10 19:10:41 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	move_l(t_env *e)
{
	if (e->o.iso)
	{
		e->origin.y += e->scale;
		e->origin.x -= 2 * e->scale;
		set(e);
		iso(e);
		draw(e->o.t2, e);
	}
	else
	{
		e->origin.x -= 5;
		set(e);
		draw(e->o.tab, e);
	}
}

static void	move_r(t_env *e)
{
	if (e->o.iso)
	{
		e->origin.y -= e->scale;
		e->origin.x += 2 * e->scale;
		set(e);
		iso(e);
		draw(e->o.t2, e);
	}
	else
	{
		e->origin.x += 5;
		set(e);
		draw(e->o.tab, e);
	}
}

static void	move_d(t_env *e)
{
	if (e->o.iso)
	{
		e->origin.y += 4 * e->scale;
		e->origin.x += 2 * e->scale;
		set(e);
		iso(e);
		draw(e->o.t2, e);
	}
	else
	{
		e->origin.y += 5;
		set(e);
		draw(e->o.tab, e);
	}
}

static void	move_u(t_env *e)
{
	if (e->o.iso)
	{
		e->origin.y -= 4 * e->scale;
		e->origin.x -= 2 * e->scale;
		set(e);
		iso(e);
		draw(e->o.t2, e);
	}
	else
	{
		e->origin.y -= 5;
		set(e);
		draw(e->o.tab, e);
	}
}

void		move(int keycode, t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (keycode == 123)
		move_l(e);
	else if (keycode == 124)
		move_r(e);
	else if (keycode == 125)
		move_d(e);
	else if (keycode == 126)
		move_u(e);
}
