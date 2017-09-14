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

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# define WIDTH 1280;
# define HEIGHT 800;
# define T tab[i][k]

# define GREEN	0x009688
# define YELLOW	0xfeff77
# define BLUE	0x4162ff
# define PINK	0xff0097
# define WHITE	0xFFFFFF
# define BROWN	0x654432

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
	int		xoffset;
	int		yoffset;
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
	int			alt;

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
int						quit(t_env *e);
int						init(t_env *e);
void					tg_alt(t_env *e);
void					tg_rota(t_env *e);
void					tg_trace(t_env *e);
void					init_img(t_env *e);
t_point					**tab_dup(t_obj *o);
void					free_tab(char **tab);
int						expose_hook(t_env *e);
int						zoom(int keycode, t_env *e);
void					move(int keycode, t_env *e);
t_env					*parser(char *arg, t_env *e);
void					color_p(t_point *p, t_env *e);
void					draw(t_point **tab, t_env *e);
void					pitchit(int keycode, t_env *e);
void					trace(t_point **tab, t_env *e);
void					put_pixel(t_point *p, t_env *e);
int						key_hook(int keycode, t_env *e);
void					bresenham(t_point a, t_point b, t_env *e);
int						mouse_hook(int button, int x, int y, t_env *e);
int						mlx_hook(void *win_ptr, int x_event, int x_mask,
						int (*funct)(), void *param);

#endif
