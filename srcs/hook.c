/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 19:10:17 by qdurot            #+#    #+#             */
/*   Updated: 2017/09/10 19:10:41 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		quit(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 113 || keycode == 53 || keycode == 12)
		quit(e);
	else if (keycode == 49)
		mlx_clear_window(e->mlx, e->win);
	else if (keycode == 13)
		tg_rota(e);
	else if (keycode == 14)
		tg_trace(e);
	else if (keycode >= 123 && keycode <= 126)
		move(keycode, e);
	else if (keycode == 27 || keycode == 24)
		zoom(keycode, e);
	else if (keycode == 15)
		iso(e);
	else if (keycode == 38 || keycode == 40)
		pitchit(keycode, e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	static int	toggle = 0;
	static int	color[5] = {WHITE, YELLOW, BLUE, PINK, GREEN};
	static int	i = 0;

	(void)x;
	(void)y;
	(void)button;
	if (toggle)
	{
		e->color = color[0];
		toggle = 0;
	}
	else if (i < 5 && !toggle)
	{
		e->color = color[++i];
		if (i == 4)
			i = 0;
		toggle = 1;
	}
	expose_hook(e);
	return (0);
}

int		expose_hook(t_env *e)
{
	(void)e;
	init_img(e);
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

void	pitchit(int keycode, t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (keycode == 38)
		e->o.pitch--;
	else
		e->o.pitch++;
	if (e->o.iso)
	{
		iso(e);
		draw(e->o.t2, e);
	}
	else
		draw(e->o.tab, e);
}
