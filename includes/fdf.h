/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 19:10:36 by qdurot            #+#    #+#             */
/*   Updated: 2017/09/10 19:10:41 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h>//	printf
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# define WIDTH 1280;
# define HEIGHT 800;
# define T tab[i][k]

typedef struct			s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}						t_point;

typedef struct			s_obj
{
	int		fd;
	int		width;
	int		height;
	char	*buf;
	int		bres;
	int		pitch;
	int		iso;
	t_point	*p;
	t_point	**tab;
	t_point	**t2;
}						t_obj;

typedef struct			s_env
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	int			scale;
	t_point		origin;
	t_obj		o;
	int			axe;

	void		*img;
	int			*data;
	int			size;
	int			bpp;
	int			endian;
	int			color;

}						t_env;

typedef struct s_bres	t_bres;
struct					s_bres
{
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		err;
	int		e2;
};

void					set(t_env *e);
void					iso(t_env *e);
void					quit(t_env *e);
int						init(t_env *e);
void					tg_rota(t_env *e);
void					tg_trace(t_env *e);
void					init_img(t_env *e);
t_point					**tab_dup(t_obj *o);
int						expose_hook(t_env *e);
void					init_point(t_point *p);
void					z_rot(t_env *e, int angle);
void					x_rot(t_env *e, int angle);
void					y_rot(t_env *e, int angle);
int						zoom(int keycode, t_env *e);
void					move(int keycode, t_env *e);
t_env					*parser(char *arg, t_env *e);
void					color_p(t_point *p, t_env *e);
void					draw(t_point **tab, t_env *e);
void					pitchit(int keycode, t_env *e);
void					trace(t_point **tab, t_env *e);
void					rota(t_env *e, int axe, int a);
void					put_pixel(t_point *p, t_env *e);
int						key_hook(int keycode, t_env *e);
void					bresenham(t_point a, t_point b, t_env *e);
int						mouse_hook(int button, int x, int y, t_env *e);
t_point					*newmap(void const *content, size_t content_size);

#endif
