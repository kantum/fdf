#ifndef FDF_H
# define FDF_H

# define RED	= 0xFF0000
# define GREEN	= 0x00FF00
# define BLUE	= 0x0000FF

# include <stdlib.h>
# include <stdio.h>		//printf()
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# define WIDTH 1280;
# define HEIGHT 800;

typedef struct s_point	t_point;
struct					s_point
{
	int					x;
	int					y;
	int					z;
	int					color;
};

typedef struct s_env	t_env;
struct					s_env
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			totalsize;
	int			win_width;
	int			win_height;

	int			fd;

	int			x;
	int			y;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			color;
	int			ex;
	int			ey;
	int			dx;
	int			dy;

	int			bres;
	int			scale;
	int			**tab;
	t_point		*m;
	char		*buf;
};

void					tg_trace(t_env *e);
void					quit(t_env *e);
void					show(t_env *e);
void					tg_iso(t_env *e);
int						isometric(t_env *e);
void					red_point(t_env *e);
void					show_m(t_env *e);
int						expose_hook(t_env *e);
int						zoom(int keycode, t_env *e);
t_env					*parser(char *arg, t_env *e);
int						key_hook(int keycode, t_env *e);
void					trace(t_env *e);
void					bresenham(int x, int x1, int y, int y1, t_env *e);
void					put_pixel(void *mlx, void *win, int x, int y, int color);
int						mouse_hook(int button, int x, int y, t_env *e);

#endif
